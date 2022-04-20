#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/area3d.hpp>
using namespace godot;

#include "HealthBar.h"


void HealthBar::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &HealthBar::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &HealthBar::_process);
    
	ClassDB::bind_method(D_METHOD("update"), &HealthBar::update);
	ClassDB::bind_method(D_METHOD("setTeam"), &HealthBar::setTeam);
}
