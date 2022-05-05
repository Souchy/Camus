#include "EntityData.h"
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void EntityData::_bind_methods() {
    // Signals.
    ADD_SIGNAL(MethodInfo("update"));
    ClassDB::bind_method(D_METHOD("signal_update"), &EntityData::signal_update);

    ClassDB::bind_method(D_METHOD("test"), &EntityData::test);

    ClassDB::bind_method(D_METHOD("setTeam", "team"), &EntityData::setTeam);
    ClassDB::bind_method(D_METHOD("getTeam"), &EntityData::getTeam);
    ClassDB::bind_method(D_METHOD("setName", "name"), &EntityData::setName);
    ClassDB::bind_method(D_METHOD("getName"), &EntityData::getName);
    ClassDB::bind_method(D_METHOD("setPrice", "price"), &EntityData::setPrice);
    ClassDB::bind_method(D_METHOD("getPrice"), &EntityData::getPrice);
    ClassDB::bind_method(D_METHOD("setBounty", "bounty"), &EntityData::setBounty);
    ClassDB::bind_method(D_METHOD("getBounty"), &EntityData::getBounty);
    ClassDB::bind_method(D_METHOD("setAI", "ai"), &EntityData::setAI);
    ClassDB::bind_method(D_METHOD("getAI"), &EntityData::getAI);
    ClassDB::bind_method(D_METHOD("setLife", "life"), &EntityData::setLife);
    ClassDB::bind_method(D_METHOD("getLife"), &EntityData::getLife);
    ClassDB::bind_method(D_METHOD("setLifeMax", "lifemax"), &EntityData::setLifeMax);
    ClassDB::bind_method(D_METHOD("getLifeMax"), &EntityData::getLifeMax);
    ClassDB::bind_method(D_METHOD("setArmour", "armour"), &EntityData::setArmour);
    ClassDB::bind_method(D_METHOD("getArmour"), &EntityData::getArmour);
    ClassDB::bind_method(D_METHOD("setAttackDamage", "attack"), &EntityData::setAttackDamage);
    ClassDB::bind_method(D_METHOD("getAttackDamage"), &EntityData::getAttackDamage);
    ClassDB::bind_method(D_METHOD("setAttackTime", "attackTime"), &EntityData::setAttackTime);
    ClassDB::bind_method(D_METHOD("getAttackTime"), &EntityData::getAttackTime);
    ClassDB::bind_method(D_METHOD("setBulletTime", "bulletTime"), &EntityData::setBulletTime);
    ClassDB::bind_method(D_METHOD("getBulletTime"), &EntityData::getBulletTime);
    ClassDB::bind_method(D_METHOD("setPenetration", "penetration"), &EntityData::setPenetration);
    ClassDB::bind_method(D_METHOD("getPenetration"), &EntityData::getPenetration);
    ClassDB::bind_method(D_METHOD("setRange", "range"), &EntityData::setRange);
    ClassDB::bind_method(D_METHOD("getRange"), &EntityData::getRange);
	
    ClassDB::bind_method(D_METHOD("setAerial", "aerial"), &EntityData::setAerial);
    ClassDB::bind_method(D_METHOD("getAerial"), &EntityData::getAerial);
    ClassDB::bind_method(D_METHOD("setCamo", "camo"), &EntityData::setCamo);
    ClassDB::bind_method(D_METHOD("getCamo"), &EntityData::getCamo);
    ClassDB::bind_method(D_METHOD("setAntiAerial", "antiAerial"), &EntityData::setAntiAerial);
    ClassDB::bind_method(D_METHOD("getAntiAerial"), &EntityData::getAntiAerial);
    ClassDB::bind_method(D_METHOD("setAntiCamo", "antiCamo"), &EntityData::getAntiCamo);
    ClassDB::bind_method(D_METHOD("getAntiCamo"), &EntityData::getAntiCamo);

    ADD_GROUP("Test group", "group_");
    ADD_SUBGROUP("Test subgroup", "group_subgroup_");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "team"), "getTeam", "setTeam");
}


EntityData::EntityData() {
}

EntityData::~EntityData() {
}

void EntityData::signal_update() { //(const String& name, int value) {
    emit_signal("update");         //, name, value);
}

void EntityData::test() {
    UtilityFunctions::print("EntityData tested.");
}

// --

void EntityData::setTeam(int team) {
    this->team = team;
}

int EntityData::getTeam() {
    return team;
}

void EntityData::setName(String name) {
    this->name = name;
}

String EntityData::getName() {
    return name;
}

void EntityData::setPrice(int price) {
    this->price = price;
}

int EntityData::getPrice() {
    return price;
}

void EntityData::setBounty(int bounty) {
    this->bounty = bounty;
}

int EntityData::getBounty() {
    return bounty;
}

void EntityData::setAI(String ai) {
    this->ai = ai;
}

String EntityData::getAI() {
    return ai;
}

// --

void EntityData::setLife(double life) {
    this->life = life;
}

double EntityData::getLife() {
    return life;
}

void EntityData::setLifeMax(double lifemax) {
    this->lifemax = lifemax;
}

double EntityData::getLifeMax() {
    return lifemax;
}

void EntityData::setArmour(double armour) {
    this->armour = armour;
}

double EntityData::getArmour() {
    return armour;
}

void EntityData::setAttackDamage(double attackDamage) {
    this->attackDamage = attackDamage;
}

double EntityData::getAttackDamage() {
    return attackDamage;
}

void EntityData::setAttackTime(double attackTime) {
    this->attackTime = attackTime;
}

double EntityData::getAttackTime() {
    return attackTime;
}

void EntityData::setBulletTime(double bulletTime) {
    this->bulletTime = bulletTime;
}

double EntityData::getBulletTime() {
    return bulletTime;
}

void EntityData::setPenetration(double penetration) {
    this->penetration = penetration;
}

double EntityData::getPenetration() {
    return penetration;
}

void EntityData::setRange(double range) {
    this->range = range;
}

double EntityData::getRange() {
    return range;
}

// --

void EntityData::setAerial(bool aerial) {
    this->aerial = aerial;
}

bool EntityData::getAerial() {
    return aerial;
}

void EntityData::setCamo(bool camo) {
    this->camo = camo;
}

bool EntityData::getCamo() {
    return camo;
}

void EntityData::setAntiAerial(bool antiAerial) {
    this->antiAerial = antiAerial;
}

bool EntityData::getAntiAerial() {
    return antiAerial;
}

void EntityData::setAntiCamo(bool antiCamo) {
    this->antiCamo = antiCamo;
}

bool EntityData::getAntiCamo() {
    return antiCamo;
}
