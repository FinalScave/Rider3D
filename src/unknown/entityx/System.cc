
#include "System.h"

namespace unknown {

BaseSystem::Family BaseSystem::family_counter_;

BaseSystem::~BaseSystem() {
}

void SystemManager::update_all(TimeDelta dt) {
  assert(initialized_ && "SystemManager::configure() not called");
  for (auto &pair : systems_) {
    pair.second->update(entity_manager_, event_manager_, dt);
  }
}

void SystemManager::configure() {
  for (auto &pair : systems_) {
    pair.second->configure(entity_manager_, event_manager_);
  }
  initialized_ = true;
}

}  // namespace unknown
