
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


class EntityData;

class Tower : public Node3D {
	GDCLASS(Tower, Node3D);

protected:
	static void _bind_methods();

private:
	Ref<EntityData> data;

public:
	Tower();
	~Tower();
	//void setData(const EntityData& data);
	//EntityData getData() const;
	void setData(const Ref<EntityData>& dat);
	Ref<EntityData> getData() const;

	//EntityData* return_extended_ref() const;
	//Ref<EntityData> extended_ref_checks(Ref<EntityData> p_ref) const;
};
