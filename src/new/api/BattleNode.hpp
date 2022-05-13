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
using namespace std;

// Can be Towers, Units, Bases
class BattleNode : public Node3D {
	GDCLASS(BattleNode, Node3D);

protected:
	static void _bind_methods();

private:
    TerrainEntity data;
    Weapon weapon;
	//Game* game;
	//list<Unit*> enemiesInArea;
	//string soundPath = "G:/Assets/pack/kenney/kenney_impactsounds/Audio/footstep_carpet_000.ogg";

public:
	BattleNode();
	~BattleNode();

	void _ready() override;
	void _process(double delta) override;
	
	virtual void turn(); //BasicUnit* turn();
	virtual void shoot(); //void shoot(BasicUnit* target);
	virtual void death();
	
	virtual void _onEntityEnteredRange(Area3D area);
	virtual void _onEntityExitedRange(Area3D area);
    virtual void _onEntityEnteredHitbox(Area3D area);
    virtual void _onEntityExitedHitbox(Area3D area);
    
    virtual void setData(TerrainEntity entity);
    virtual TerrainEntity getData();
    virtual void setWeapon(Weapon weapon);
    virtual Weapon getWeapon();
};


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
	ClassDB::bind_method(D_METHOD("_onEntityEnteredRange", "area"), &BattleNode::_onEntityEnteredRange);
	ClassDB::bind_method(D_METHOD("_onEntityExitedRange", "area"), &BattleNode::_onEntityExitedRange);
	ClassDB::bind_method(D_METHOD("_onEntityEnteredHitbox", "area"), &BattleNode::_onEntityEnteredHitbox);
	ClassDB::bind_method(D_METHOD("_onEntityExitedHitbox", "area"), &BattleNode::_onEntityExitedHitbox);
}

void BattleNode::_ready() {

}
void BattleNode::_process(double delta) {

}
void BattleNode::turn() {

}
void BattleNode::shoot() {

}
void BattleNode::_onEntityEnteredRange(Area3D area) {

}
void BattleNode::_onEntityExitedRange(Area3D area) {

}
void BattleNode::_onEntityEnteredHitbox(Area3D area) {

}
void BattleNode::_onEntityExitedHitbox(Area3D area) {

}
void BattleNode::setData(TerrainEntity data){
    this->data = data;
}
TerrainEntity BattleNode::getData() {
    return this->data;
}
void BattleNode::setWeapon(Weapon weapon) {
    this->weapon = weapon;
}
Weapon BattleNode::getWeapon() {
    return this->weapon;
}