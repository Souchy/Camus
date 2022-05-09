#pragma once

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
using namespace godot;


class Entity : public RefCounted {
	GDCLASS(Entity, RefCounted);

protected:
	static void _bind_methods();

private:
    String name;
    int teamId;
	bool active;

public:
	Entity();
	~Entity();

	void setName(String name);
	String getName();
	void setTeamId(int team);
	int getTeamId();
	void setActive(bool active);
	bool getActive();
};