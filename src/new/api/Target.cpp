#include "Target.h"
#include "Entity.h"
#include "TerrainEntity.h"
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void Target::_bind_methods() {  
    ClassDB::bind_method(D_METHOD("setEntity", "name"), &Target::setEntity);
    ClassDB::bind_method(D_METHOD("getEtity"), &Target::getEntity);
}

Target::Target() {
}

Target::~Target() {
}

// --

void Target::setEntity(Ref<TerrainEntity> entity) {
    this->entity = entity;
}
Ref<TerrainEntity> Target::getEntity() {
    return entity;
}

float Target::getX() {
    if(this->entity.ptr()->getActive()){
        return this->entity.ptr()->getPos().x;
    }
    return this->pos.x;
}
float Target::getY() {
    if(this->entity.ptr()->getActive()){
        return entity.ptr()->getPos().x;
    }
    return this->pos.y;
}
float Target::getZ() {
    if(this->entity.ptr()->getActive()){
        return entity.ptr()->getPos().x;
    }
    return this->pos.z;
}