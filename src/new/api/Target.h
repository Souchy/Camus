#pragma once

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
using namespace godot;

#include "TerrainEntity.h"

class Target : public RefCounted {
	GDCLASS(Target, RefCounted);

protected:
	static void _bind_methods();

private:
    TerrainEntity entity;
    godot::Vector3 pos;

public:
	Target();
	~Target();

    void setEntity(TerrainEntity entity);
    TerrainEntity getEntity();
        
    float getX();
    float getY();
    float getZ();
};
