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
#include "Weapon.h"
#include "EntityData.h"
using namespace std;

struct BulletData {
    // signal update
    int team = 0;
    
    float damage = 0;
    float penetration = 0;
    bool followsTarget = false;
    int pierces = 0;
    int chains = 0;
    int forks = 0;
    bool explodes = false;
    float explosionRadius = 1;
};

class Projectile : public Node3D {
	GDCLASS(Projectile, Node3D);

protected:
	static void _bind_methods();
    
private:

public:
	Projectile();
	~Projectile();

    //Ref<EntityData> data; // = EntityData::_new();
    BulletData data;
    Node3D* target;
    Vector3 direction = Vector3(0,0,0);
    float speed = 20.0;
    float time = 0;
    float max_time_s = 1;
    float percentSeeking = 1;
    bool active = true;

	void _ready() override;
	void _process(float delta);

};

