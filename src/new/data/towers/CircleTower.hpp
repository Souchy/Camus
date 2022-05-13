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
#include "../../api/BattleNode.hpp"
#include "BasicTower.hpp"
using namespace std;

class CircleTower : public BasicTower {
	GDCLASS(CircleTower, BasicTower);

protected:
	static void _bind_methods();

private:

public:
	CircleTower();
	~CircleTower();

	void _ready() override;
	void _process(double delta) override;
	
	void turn() override; //BasicUnit* turn();
	void shoot() override; //void shoot(BasicUnit* target);
	void death() override;

	// void _onEntityEnteredRange(Area3D area) override;
	// void _onEntityExitedRange(Area3D area) override;
    // void _onEntityEnteredHitbox(Area3D area) override;
    // void _onEntityExitedHitbox(Area3D area) override;
};

void CircleTower::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &CircleTower::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &CircleTower::_process);

	ClassDB::bind_method(D_METHOD("getData"), &CircleTower::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &CircleTower::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	ClassDB::bind_method(D_METHOD("getWeapon"), &CircleTower::getWeapon);
	ClassDB::bind_method(D_METHOD("setWeapon", "weapon"), &CircleTower::setWeapon);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "weapon"), "setWeapon", "getWeapon");
	
	ClassDB::bind_method(D_METHOD("turn"), &CircleTower::turn);
	ClassDB::bind_method(D_METHOD("shoot"), &CircleTower::shoot);
	ClassDB::bind_method(D_METHOD("death"), &CircleTower::death);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &CircleTower::_onEntityEnteredRange);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &CircleTower::_onEntityExitedRange);
	// ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &CircleTower::_onEntityEnteredHitbox);
	// ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &CircleTower::_onEntityExitedHitbox);
}

void CircleTower::death() {

}