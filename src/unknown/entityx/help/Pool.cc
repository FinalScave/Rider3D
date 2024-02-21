
#include "Pool.h"

namespace unknown {

BasePool::~BasePool() {
  for (char *ptr : blocks_) {
    delete[] ptr;
  }
}

}  // namespace unknown
