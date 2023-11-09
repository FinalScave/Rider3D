#pragma once

#include <atomic>
#include <string>

#include "macro_util.h"

namespace logger {

class Logger {
 public:
  enum class Level {
    DEBUG_LEVEL,
    INFO_LEVEL,
    WARN_LEVEL,
    ERROR_LEVEL,
    FATAL_LEVEL,
  };

  /**
   * 获取单例
   */
  static Logger* Instance() {
    return instance_;
  }
  /**
   * 根据日志级别打印日志
   */
  void Log(Level log_level, const char* fmt, ...);

 public:
  // static void set_trace_id(uint64_t trace_id = 0);
  // static uint64_t trace_id();
  static void set_trace_id(const uint64_t trace_id = 0);
  static uint64_t trace_id();

 private:
  Logger();
  ~Logger();

 private:
  static std::string GenLogPrefix();

 private:
  static Logger* instance_;
  Level priority_ = Level::DEBUG_LEVEL;
  std::atomic<bool> receive_fatal_ = {false};

 private:
  DISALLOW_COPY_AND_ASSIGN(Logger);
};

}  // namespace logger
