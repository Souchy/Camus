#include "Projectile.h"

#include <godot_cpp/classes/area3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/sprite3d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void Projectile::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_ready"), &Projectile::_ready);
    ClassDB::bind_method(D_METHOD("_process"), &Projectile::_process);

    // ClassDB::bind_method(D_METHOD("getData"), &Projectile::getData);
    // ClassDB::bind_method(D_METHOD("setData", "data"), &Projectile::setData);
    // ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
}

Projectile::Projectile() {
    UtilityFunctions::print("Projectile Constructor.");
}
Projectile::~Projectile() {
    UtilityFunctions::print("Projectile Destructor.");
}

void Projectile::_ready() {
}
void Projectile::_process(float delta) {
}
