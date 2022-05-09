#include "Entity.h"
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void Entity::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("setTeamId", "teamId"), &Entity::setTeamId);
    ClassDB::bind_method(D_METHOD("getTeamId"), &Entity::getTeamId);
    ClassDB::bind_method(D_METHOD("setName", "name"), &Entity::setName);
    ClassDB::bind_method(D_METHOD("getName"), &Entity::getName);
    ClassDB::bind_method(D_METHOD("setActive", "active"), &Entity::setActive);
    ClassDB::bind_method(D_METHOD("getActive"), &Entity::getActive);
}

Entity::Entity()
{
}

Entity::~Entity()
{
}

// --

void Entity::setTeamId(int teamId)
{
    this->teamId = teamId;
}
int Entity::getTeamId()
{
    return teamId;
}
void Entity::setName(String name)
{
    this->name = name;
}
String Entity::getName()
{
    return name;
}
void Entity::setActive(bool active) {
    this->active = active;
}
bool Entity::getActive() {
    return active;
}
