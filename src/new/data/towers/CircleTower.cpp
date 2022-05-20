#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/cylinder_mesh.hpp>
#include <godot_cpp/classes/cylinder_mesh.hpp>
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
#include "CircleTower.h"
using namespace std;

void CircleTower::_bind_methods() {
	// ClassDB::bind_method(D_METHOD("_ready"), &CircleTower::_ready);
	// ClassDB::bind_method(D_METHOD("_process"), &CircleTower::_process);

	// ClassDB::bind_method(D_METHOD("getData"), &CircleTower::getData);
	// ClassDB::bind_method(D_METHOD("setData", "data"), &CircleTower::setData);
	// ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	// ClassDB::bind_method(D_METHOD("getWeapon"), &CircleTower::getWeapon);
	// ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &CircleTower::setWeapon);
	// ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &CircleTower::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &CircleTower::shoot);
	ClassDB::bind_method(D_METHOD("death"), &CircleTower::death);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &CircleTower::_onEntityEnteredRange);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &CircleTower::_onEntityExitedRange);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &CircleTower::_onEntityEnteredHitbox);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &CircleTower::_onEntityExitedHitbox);
}


CircleTower::CircleTower(){
	// UtilityFunctions::print("C++ CircleTower ", id," constructor.");
}
CircleTower::~CircleTower(){
}

void CircleTower::_enter_tree(){
	// UtilityFunctions::print("C++ CircleTower ", id," enter_tree.");
	BasicTower::_enter_tree();
}
void CircleTower::_ready() {
	// UtilityFunctions::print("C++ CircleTower ", id," ready.");
    // BasicTower::_ready();
	JSON json;
	// godot::String s = json.stringify(this);

	File file;
	file.open("circleTower.json", File::WRITE);
	file.store_string(json.stringify(this, "\t"));
	file.close();
}
void CircleTower::_process(double delta) {
    // BasicTower::_process(delta);
}

void CircleTower::createMesh(){
	// UtilityFunctions::print("C++ CircleTower ", id," createMesh.");
	MeshInstance3D* meshi = new MeshInstance3D();
	CylinderMesh* mesh = new CylinderMesh();
	mesh->set_bottom_radius(1);
	mesh->set_top_radius(1);
	mesh->set_height(1);
	meshi->set_mesh(mesh);
	meshi->set_name("bodyMesh");
    this->add_child(meshi);
}
void CircleTower::turn() {

}
void CircleTower::shoot() {

}
void CircleTower::death() {

}