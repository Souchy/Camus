#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/cylinder_mesh.hpp>
#include <godot_cpp/classes/box_mesh.hpp>
#include <godot_cpp/classes/area3d.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/classes/file.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

#include <string>
#include "../../api/Entity.h"
#include "../../api/TerrainEntity.h"
#include "../../api/Weapon.h"
#include "../units/BasicUnit.hpp"
#include "../../api/BattleNode.h"
#include "BasicTower.h"
using namespace std;


void BasicTower::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("_ready"), &BasicTower::_ready);
	// ClassDB::bind_method(D_METHOD("_process"), &BasicTower::_process);

	ClassDB::bind_method(D_METHOD("getData"), &BasicTower::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &BasicTower::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	ClassDB::bind_method(D_METHOD("getWeapon"), &BasicTower::getWeapon);
	ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &BasicTower::setWeapon);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &BasicTower::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &BasicTower::shoot);
	ClassDB::bind_method(D_METHOD("death"), &BasicTower::death);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &BasicTower::_onEntityEnteredRange);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &BasicTower::_onEntityExitedRange);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &BasicTower::_onEntityEnteredHitbox);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &BasicTower::_onEntityExitedHitbox);
}

BasicTower::BasicTower(){
	// UtilityFunctions::print("C++ BasicTower ", id," constructor.");
}
BasicTower::~BasicTower(){

}

void BasicTower::_enter_tree(){
	// UtilityFunctions::print("C++ BasicTower ", id," enter_tree.");
	BattleNode::_enter_tree();
}
void BasicTower::_ready() {
	// UtilityFunctions::print("C++ BasicTower ", id," ready.");
	JSON json;
	//godot::String s = json.stringify(this, "\t");
	
	File file;
	file.open("basicTower.json", File::WRITE);
	file.store_string(json.stringify(this, "\t"));
	file.store_string(json.stringify(this->getData(), "\t"));
	file.store_string(json.stringify(this->getWeapon(), "\t"));
	file.close();
}
void BasicTower::_process(double delta) {
	// UtilityFunctions::print("C++ BasicTower process.");
}

void BasicTower::createMesh(){
	// UtilityFunctions::print("C++ BasicTower ", id," createMesh.");
	MeshInstance3D* meshi = new MeshInstance3D();
	BoxMesh* mesh = new BoxMesh();
	Vector3 v = Vector3(1,1,1);
	mesh->set_size(v);
	meshi->set_mesh(mesh);
	meshi->set_name("bodyMesh");
    this->add_child(meshi);
}
void BasicTower::turn() {

}
void BasicTower::shoot() {

}
void BasicTower::death() {

}
// void BasicTower::_onEntityEnteredRange(Area3D area) {

// }
// void BasicTower::_onEntityExitedRange(Area3D area) {

// }
// void BasicTower::_onEntityEnteredHitbox(Area3D area) {

// }
// void BasicTower::_onEntityExitedHitbox(Area3D area) {

// }
