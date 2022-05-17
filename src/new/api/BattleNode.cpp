#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/area3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

#include <string>
#include "Entity.h"
#include "TerrainEntity.h"
#include "Weapon.h"
#include "BattleNode.h"
using namespace std;


void BattleNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &BattleNode::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &BattleNode::_process);

	ClassDB::bind_method(D_METHOD("getData"), &BattleNode::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &BattleNode::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	ClassDB::bind_method(D_METHOD("getWeapon"), &BattleNode::getWeapon);
	ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &BattleNode::setWeapon);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &BattleNode::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &BattleNode::shoot);
	ClassDB::bind_method(D_METHOD("death"), &BattleNode::death);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &BattleNode::_onEntityEnteredRange);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &BattleNode::_onEntityExitedRange);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &BattleNode::_onEntityEnteredHitbox);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &BattleNode::_onEntityExitedHitbox);
}

BattleNode::BattleNode(){
	id = BattleNode::idCounter();
	// UtilityFunctions::print("C++ BattleNode ", id, " constructor.");
}

BattleNode::~BattleNode(){
	
}

void BattleNode::_ready() {
	UtilityFunctions::print("C++ BattleNode ", id," ready.");
	createMesh();
}
void BattleNode::_process(double delta) {
}
void BattleNode::createMesh(){
	UtilityFunctions::print("C++ BattleNode ", id," createMesh.");
}
void BattleNode::turn() {

}
void BattleNode::shoot() {

}
void BattleNode::death(){
	
}
void BattleNode::_onEntityEnteredRange(Area3D area) {

}
void BattleNode::_onEntityExitedRange(Area3D area) {

}
void BattleNode::_onEntityEnteredHitbox(Area3D area) {

}
void BattleNode::_onEntityExitedHitbox(Area3D area) {

}
void BattleNode::setData(Ref<TerrainEntity> data) {
    this->data = data;
}
Ref<TerrainEntity> BattleNode::getData() {
    return this->data;
}
void BattleNode::setWeapon(Ref<Weapon> weapon) {
    this->weapon = weapon;
}
Ref<Weapon> BattleNode::getWeapon() {
    return this->weapon;
}