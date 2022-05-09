#include "Weapon.h"
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void Weapon::_bind_methods() {
    ClassDB::bind_method(D_METHOD("setAmmo", "ammo"), &Weapon::setAmmo);
    ClassDB::bind_method(D_METHOD("getAmmo"), &Weapon::getAmmo);
    ClassDB::bind_method(D_METHOD("setAttackDamage", "attack"), &Weapon::setAttackDamage);
    ClassDB::bind_method(D_METHOD("getAttackDamage"), &Weapon::getAttackDamage);
    ClassDB::bind_method(D_METHOD("setAttackTime", "attackTime"), &Weapon::setAttackTime);
    ClassDB::bind_method(D_METHOD("getAttackTime"), &Weapon::getAttackTime);
    ClassDB::bind_method(D_METHOD("setBulletTravelTimeBonus", "bulletTime"), &Weapon::setBulletTravelTimeBonus);
    ClassDB::bind_method(D_METHOD("getBulletTravelTimeBonus"), &Weapon::getBulletTravelTimeBonus);
    ClassDB::bind_method(D_METHOD("setPenetration", "penetration"), &Weapon::setPenetration);
    ClassDB::bind_method(D_METHOD("getPenetration"), &Weapon::getPenetration);
    ClassDB::bind_method(D_METHOD("setRange", "range"), &Weapon::setRange);
    ClassDB::bind_method(D_METHOD("getRange"), &Weapon::getRange);
    
    ClassDB::bind_method(D_METHOD("setAntiAerial", "antiAerial"), &Weapon::setAntiAerial);
    ClassDB::bind_method(D_METHOD("getAntiAerial"), &Weapon::getAntiAerial);
    ClassDB::bind_method(D_METHOD("setAntiCamo", "antiCamo"), &Weapon::getAntiCamo);
    ClassDB::bind_method(D_METHOD("getAntiCamo"), &Weapon::getAntiCamo);
}

Weapon::Weapon() {
}

Weapon::~Weapon() {
}

// --

void shoot(TerrainEntity source) { //, Positional target) {

}

void Weapon::setAmmo(int ammo) {
    this->ammo = ammo;
}
int Weapon::getAmmo() {
    return ammo;
}
void Weapon::setAttackDamage(double attackDamage) {
    this->attackDamage = attackDamage;
}
double Weapon::getAttackDamage() {
    return attackDamage;
}
void Weapon::setAttackTime(double attackTime) {
    this->attackTime = attackTime;
}
double Weapon::getAttackTime() {
    return attackTime;
}
void Weapon::setBulletTravelTimeBonus(double bulletTravelTimeBonus) {
    this->bulletTravelTimeBonus = bulletTravelTimeBonus;
}
double Weapon::getBulletTravelTimeBonus() {
    return bulletTravelTimeBonus;
}
void Weapon::setPenetration(double penetration) {
    this->penetration = penetration;
}
double Weapon::getPenetration() {
    return penetration;
}
void Weapon::setRange(double range) {
    this->range = range;
}
double Weapon::getRange() {
    return range;
}

void Weapon::setAntiAerial(bool antiAerial) {
    this->antiAerial = antiAerial;
}
bool Weapon::getAntiAerial() {
    return antiAerial;
}
void Weapon::setAntiCamo(bool antiCamo) {
    this->antiCamo = antiCamo;
}
bool Weapon::getAntiCamo() {
    return antiCamo;
}
