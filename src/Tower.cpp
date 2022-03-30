#include "Tower.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

#include "EntityData.h"

void Tower::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getData"), &Tower::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &Tower::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
}

Tower::Tower() {
	UtilityFunctions::print("Tower Constructor.");
}

Tower::~Tower() {
	UtilityFunctions::print("Tower Destructor.");
}

//void Tower::setData(const EntityData& asdf) {
//	data = asdf;
//}
//EntityData Tower::getData() const {
//	return data;
//}


void Tower::setData(const Ref<EntityData>& dat) {
	this->data = dat;
}
Ref<EntityData> Tower::getData() const {
	return data;
}

