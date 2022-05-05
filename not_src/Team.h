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
#include "Unit.h"
#include "Tower.h"
using namespace std;

class Team { //: public Node3D {
	//GDCLASS(Tower, Node3D);

protected:
	static void _bind_methods();

private:


public:
	Team();
	~Team();
    
    string name = "";
    int team = 0;

    int life = 20;
    int lifemax = 20;
    int armour = 0;

    int gold = 100;
	list<Unit*> units;
	list<Tower*> towers;
};
