
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
#include <vector>
#include <list>
#include "Weapon.h"
#include "EntityData.h"
#include "Unit.h"
#include "../Game.h"
using namespace std;


class Tower : public Node3D {
	GDCLASS(Tower, Node3D);

protected:
	static void _bind_methods();

private:
	/*
	// this is for debug with pre-placed towers
	@export var team: int = 0
	@onready var game:Game = get_node("/root/Game");
	// this is actual data of the tower
	var data:DataTower = DataTower.new();
	*/
	Game* game;
	Ref<EntityData> data;
	//Ref<Weapon> weapon;
	bool active = false;
	list<Unit*> enemiesInArea;
	float attackCooldown = 0;
	int mode = modeFirst;
	string soundPath = "G:/Assets/pack/kenney/kenney_impactsounds/Audio/footstep_carpet_000.ogg";
	const int modeFirst = 0;
	const int modeLast = 1;
	const int modeHighestHp = 2;
	const int modeLowestHp = 3;

public:
	enum Towers {
		BasicTower,
		ShotgunTower,
		CannonTower,
		SpinningTower,
		SpreadTower
	};

	Tower();
	~Tower();
	void setData(const Ref<EntityData>& dat);
	Ref<EntityData> getData() const;

	void _ready() override;
	void _process(float delta);
	
	Unit* turn();
	void shoot(Unit* target);
	void death();
	
	void _on_area_3d_max_area_entered(Area3D area);
	void _on_area_3d_max_area_exited(Area3D area);

};

VARIANT_ENUM_CAST(Tower, Towers);
