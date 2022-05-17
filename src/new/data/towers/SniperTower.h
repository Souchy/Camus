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
#include "../../api/BattleNode.h"
#include "BasicTower.h"
using namespace std;

class SniperTower : public BasicTower {
	GDCLASS(SniperTower, BasicTower);

protected:
	static void _bind_methods();

private:

public:
	SniperTower();
	~SniperTower();

	void _enter_tree() override;
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
