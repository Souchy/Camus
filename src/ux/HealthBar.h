#pragma once

#include <godot_cpp/classes/sprite3d.hpp>
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

class HealthBar : public Sprite3D {
	GDCLASS(HealthBar, Sprite3D);

protected:
	static void _bind_methods();
    
private:

public:
	HealthBar();
	~HealthBar();

	void _ready();
	void _process(float delta);

    void update();
    void setTeam(int team);

    
	void emit_custom_signal(const String& name, int value);

};

