
#include "entityx/Event.h"

namespace unknown {

BaseEvent::Family BaseEvent::family_counter_ = 0;

BaseEvent::~BaseEvent() {
}

EventManager::EventManager() {
}

EventManager::~EventManager() {
}

}  // namespace unknown
