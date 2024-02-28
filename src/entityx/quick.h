
#pragma once

#include "entityx/Entity.h"
#include "entityx/Event.h"
#include "entityx/System.h"
#include "entityx/config.h"

namespace rider {

/**
 * A convenience class for instantiating an EventManager, EntityManager and
 * SystemManager.
 */
class EntityX {
 public:
  EntityX() : entities(events), systems(entities, events) {}

  EventManager events;
  EntityManager entities;
  SystemManager systems;
};

}  // namespace unknown
