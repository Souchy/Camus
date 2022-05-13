#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <vector>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
using namespace godot;

#include <string>
#include "EntityData.h"
#include "Projectile.h"
using namespace std;

class Unit : public Node3D {
	GDCLASS(Unit, Node3D);

protected:
	static void _bind_methods();
    
private:
	Ref<EntityData> data;
	//Ref<Weapon> weapon;

public:
	Unit();
	~Unit();
	void setData(const Ref<EntityData>& dat);
	Ref<EntityData> getData() const;

	void _ready();
	void _process(float delta);

};

