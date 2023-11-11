#include "logger.h"

#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

#include <array>
#include <cstdarg>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "log.h"
namespace logger {

namespace {

const std::unordered_map<Logger::Level, std::string> kLevel2Description = {
    {Logger::Level::DEBUG_LEVEL, "[DEBUG]"}, {Logger::Level::INFO_LEVEL, "[INFO]"},
    {Logger::Level::WARN_LEVEL, "[WARN]"},   {Logger::Level::ERROR_LEVEL, "[ERROR]"},
    {Logger::Level::FATAL_LEVEL, "[FATAL]"},
};

constexpr uint32_t kSkipFrames = 3;

void HandleSignal() {
  auto handler = [](int signal) {
    printf("receive signal: %d\n", signal);
    Logger::Instance()->Log(Logger::Level::FATAL_LEVEL, "Exiting due to receive signal: %d", signal);
    exit(0);
  };

  signal(SIGHUP, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGPIPE, SIG_IGN);
#ifdef WINDOWS
  //do nothing
#else
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGCHLD, SIG_IGN);
#endif
  signal(SIGTERM, SIG_IGN);

  signal(SIGBUS, handler);   // 10: Bus error (bad memory access)
  signal(SIGSEGV, handler);  // 11: Invalid memory reference
  signal(SIGABRT, handler);  // 6: Abort signal from abort(3)
  signal(SIGILL, handler);   // 4: Illegal Instruction
  signal(SIGFPE, handler);   // 8: Floating point exception
}

}  // namespace

thread_local int t_pid = ::getpid();
thread_local uint64_t t_traceid = 0;

Logger* Logger::instance_ = new Logger();

Logger::Logger() {
  // 注册信号处理函数
  HandleSignal();
}

Logger::~Logger() {

}

void Logger::Log(Level log_level, const char* fmt, ...) {
  if (log_level < priority_) {
    return;
  }

  std::string new_fmt = GenLogPrefix() + kLevel2Description.at(log_level) + fmt;
  if (log_level == Level::FATAL_LEVEL) {
    new_fmt += "\n\tExiting due to FATAL log";
    new_fmt += "\n\tCall Stack:";
  }

  va_list args;
  {
    va_start(args, fmt);
    // ERROR 及 FATAL 日志输出到控制台
    if (log_level >= Level::ERROR_LEVEL) {
// https://stackoverflow.com/questions/36120717/correcting-format-string-is-not-a-string-literal-warning
#if defined(__has_warning)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif
      vprintf((new_fmt + "\n").c_str(), args);
#if defined(__has_warning)
#pragma clang diagnostic pop
#endif
    }
    va_end(args);
  }
}

std::string Logger::GenLogPrefix() {
  struct timeval now;
  ::gettimeofday(&now, nullptr);
  struct tm tm_now;
#ifdef WINDOWS
  ::localtime_r((const time_t *) &now.tv_sec, &tm_now);
#else
  ::localtime_r(&now.tv_sec, &tm_now);
#endif
  char time_str[100];
  snprintf(time_str, sizeof(time_str), "[%04d-%02d-%02d %02d:%02d:%02d.%06ld][%d:%lx]", tm_now.tm_year + 1900,
           tm_now.tm_mon + 1, tm_now.tm_mday, tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec, now.tv_usec, t_pid,
           t_traceid);
  return time_str;
}

void Logger::set_trace_id(const uint64_t trace_id) {
    t_traceid = trace_id;
}

uint64_t Logger::trace_id() {
  return t_traceid;
}

}  // namespace logger
