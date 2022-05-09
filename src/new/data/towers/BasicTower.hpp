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
#include "../../api/BattleEntity.hpp"
using namespace std;

class BasicTower : public BattleNode {
	GDCLASS(BasicTower, BattleNode);

protected:
	static void _bind_methods();

private:

public:
	BasicTower();
	~BasicTower();

	void _ready() override;
	void _process(float delta) override;
	
	void turn() override; //BasicUnit* turn();
	void shoot(); //void shoot(BasicUnit* target);
	void death();
	
	void _onEntityEnteredRange(Area3D area);
	void _onEntityExitedRange(Area3D area);
    void _onEntityEnteredHitbox(Area3D area);
    void _onEntityExitedHitbox(Area3D area);
};


void BasicTower::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &BasicTower::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &BasicTower::_process);

	ClassDB::bind_method(D_METHOD("getData"), &BasicTower::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &BasicTower::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	ClassDB::bind_method(D_METHOD("getWeapon"), &BasicTower::getWeapon);
	ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &BasicTower::setWeapon);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &BasicTower::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &BasicTower::shoot);
	ClassDB::bind_method(D_METHOD("death"), &BasicTower::death);
	ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &BasicTower::_onEntityEnteredRange);
	ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &BasicTower::_onEntityExitedRange);
	ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &BattleNode::_onEntityEnteredHitbox);
	ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &BattleNode::_onEntityExitedHitbox);

}

void BasicTower::_ready() {
    
}
void BasicTower::_process(float delta) {

}
void BasicTower::turn() {

}
void BasicTower::shoot() {

}
void BasicTower::_onEntityExitedRange(Area3D area) {

}
void BasicTower::_onEntityExitedRange(Area3D area) {

}
void BasicTower::_onEntityEnteredHitbox(Area3D area) {

}
void BasicTower::_onEntityExitedHitbox(Area3D area) {

}
