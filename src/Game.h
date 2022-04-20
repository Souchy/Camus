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
using namespace std;

class Game : public Node3D {
	GDCLASS(Game, Node3D);

protected:
	static void _bind_methods();
    
private:

public:
	Game();
	~Game();

	void _ready();
	void _process(float delta);

	int otherTeam(int team);

};

