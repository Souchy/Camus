#include "Unit.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/area3d.hpp>
using namespace godot;

void Unit::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &Unit::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &Unit::_process);

	ClassDB::bind_method(D_METHOD("getData"), &Unit::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &Unit::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	
}

Unit::Unit() {
	UtilityFunctions::print("C++ Unit Constructor.");
}
Unit::~Unit() {
	UtilityFunctions::print("C++ Unit Destructor.");
}

void Unit::setData(const Ref<EntityData>& dat) {
	this->data = dat;
}
Ref<EntityData> Unit::getData() const {
	return data;
}

void Unit::_ready() {
    UtilityFunctions::print("C++ Unit ready");
}

void Unit::_process(float delta) {
    UtilityFunctions::print("C++ Unit process %s", delta);
}
