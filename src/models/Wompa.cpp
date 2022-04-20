#include "Wompa.h"
#include "EntityData.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;


void Wompa::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getData"), &Wompa::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &Wompa::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
}

Wompa::Wompa() {
	UtilityFunctions::print("Wompa Constructor.");
}

Wompa::~Wompa() {
	UtilityFunctions::print("Wompa Destructor.");
}
void Wompa::setData(const Ref<EntityData>& dat) {
	this->data = dat;
}
Ref<EntityData> Wompa::getData() const {
	return data;
}

void Wompa::_process(double delta) {
	UtilityFunctions::print("Wompa process %s", delta);
}