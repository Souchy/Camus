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
#include "Entity.h"
#include "TerrainEntity.h"
#include "Weapon.h"
using namespace std;

// Can be Towers, Units, Bases
class BattleNode : public Node3D {
	GDCLASS(BattleNode, Node3D);

protected:
	static int idCounter() {
       static int idCounter = 0;
       return idCounter++;
    }
	int id;
	static void _bind_methods();

private:
    Ref<TerrainEntity> data;
    Ref<Weapon> weapon;
	//Game* game;
	//list<Unit*> enemiesInArea;
	//string soundPath = "G:/Assets/pack/kenney/kenney_impactsounds/Audio/footstep_carpet_000.ogg";

public:
	BattleNode();
	~BattleNode();

	void _ready() override;
	void _process(double delta) override;
	
	virtual void createMesh();
	virtual void turn(); //BasicUnit* turn();
	virtual void shoot(); //void shoot(BasicUnit* target);
	virtual void death();
	
	virtual void _onEntityEnteredRange(Area3D area);
	virtual void _onEntityExitedRange(Area3D area);
    virtual void _onEntityEnteredHitbox(Area3D area);
    virtual void _onEntityExitedHitbox(Area3D area);
    
    void setData(Ref<TerrainEntity> entity);
    Ref<TerrainEntity> getData();
    void setWeapon(Ref<Weapon> weapon);
    Ref<Weapon> getWeapon();
};
