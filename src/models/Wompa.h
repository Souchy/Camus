#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/mesh.hpp>
using namespace godot;

#include <string>
#include "EntityData.h"
using namespace std;

class Wompa : public Node3D {
	GDCLASS(Wompa, Node3D);

protected:
	static void _bind_methods();

private:
	Ref<EntityData> data;

public:
	Wompa();
	~Wompa();
	void setData(const Ref<EntityData>& dat);
	Ref<EntityData> getData() const;

    void _process(double delta) override;
};
