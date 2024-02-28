
#include "Pool.h"

namespace rider {

BasePool::~BasePool() {
  for (char *ptr : blocks_) {
    delete[] ptr;
  }
}

}  // namespace unknown
