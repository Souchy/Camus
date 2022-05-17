#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/area3d.hpp>
using namespace godot;

#include <string>
#include "../../api/Entity.h"
#include "../../api/TerrainEntity.h"
#include "../../api/Weapon.h"
#include "../units/BasicUnit.hpp"
#include "../../api/BattleNode.h"
#include "BasicTower.h"
#include "SniperTower.h"
using namespace std;

void SniperTower::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("_ready"), &SniperTower::_ready);
	// ClassDB::bind_method(D_METHOD("_process"), &SniperTower::_process);

	// ClassDB::bind_method(D_METHOD("getData"), &SniperTower::getData);
	// ClassDB::bind_method(D_METHOD("setData", "data"), &SniperTower::setData);
	// ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	// ClassDB::bind_method(D_METHOD("getWeapon"), &SniperTower::getWeapon);
	// ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &SniperTower::setWeapon);
	// ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &SniperTower::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &SniperTower::shoot);
	ClassDB::bind_method(D_METHOD("death"), &SniperTower::death);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &SniperTower::_onEntityEnteredRange);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &SniperTower::_onEntityExitedRange);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &SniperTower::_onEntityEnteredHitbox);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &SniperTower::_onEntityExitedHitbox);
}


SniperTower::SniperTower(){

}
SniperTower::~SniperTower(){

}
void SniperTower::_enter_tree(){
	//UtilityFunctions::print("C++ CircleTower ", id," enter_tree.");
}
void SniperTower::_ready() {
    BasicTower::_ready();
}
void SniperTower::_process(double delta) {
    BasicTower::_process(delta);
}
void SniperTower::turn() {

}
void SniperTower::shoot() {

}
void SniperTower::death() {

}