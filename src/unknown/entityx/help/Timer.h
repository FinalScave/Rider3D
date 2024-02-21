
#pragma once

#include <chrono>

namespace unknown {
namespace help {

class Timer {
public:
  Timer();
  ~Timer();

  void restart();
  double elapsed();
private:
  std::chrono::time_point<std::chrono::system_clock> _start;
};

}  // namespace help
}  // namespace unknown
