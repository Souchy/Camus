#include "TerrainEntity.h"
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
using namespace godot;

void TerrainEntity::_bind_methods() {
    ClassDB::bind_method(D_METHOD("getName"), &TerrainEntity::getName);
    ClassDB::bind_method(D_METHOD("setPrice", "price"), &TerrainEntity::setPrice);
    ClassDB::bind_method(D_METHOD("getPrice"), &TerrainEntity::getPrice);
    ClassDB::bind_method(D_METHOD("setBounty", "bounty"), &TerrainEntity::setBounty);
    ClassDB::bind_method(D_METHOD("getBounty"), &TerrainEntity::getBounty);
    ClassDB::bind_method(D_METHOD("setAI", "ai"), &TerrainEntity::setAI);
    ClassDB::bind_method(D_METHOD("getAI"), &TerrainEntity::getAI);
    ClassDB::bind_method(D_METHOD("setLife", "life"), &TerrainEntity::setLife);
    ClassDB::bind_method(D_METHOD("getLife"), &TerrainEntity::getLife);
    ClassDB::bind_method(D_METHOD("setLifeMax", "lifemax"), &TerrainEntity::setLifeMax);
    ClassDB::bind_method(D_METHOD("getLifeMax"), &TerrainEntity::getLifeMax);
    ClassDB::bind_method(D_METHOD("setArmour", "armour"), &TerrainEntity::setArmour);
    ClassDB::bind_method(D_METHOD("getArmour"), &TerrainEntity::getArmour);
    
    ClassDB::bind_method(D_METHOD("setAerial", "aerial"), &TerrainEntity::setAerial);
    ClassDB::bind_method(D_METHOD("getAerial"), &TerrainEntity::getAerial);
    ClassDB::bind_method(D_METHOD("setCamo", "camo"), &TerrainEntity::setCamo);
    ClassDB::bind_method(D_METHOD("getCamo"), &TerrainEntity::getCamo);
}

TerrainEntity::TerrainEntity() {
}

TerrainEntity::~TerrainEntity() {
}

Vector3 TerrainEntity::getPos(){
    return pos;
}
// --

void TerrainEntity::setPrice(int price) {
    this->price = price;
}
int TerrainEntity::getPrice() {
    return price;
}
void TerrainEntity::setBounty(int bounty) {
    this->bounty = bounty;
}
int TerrainEntity::getBounty() {
    return bounty;
}
void TerrainEntity::setAI(String ai) {
    this->ai = ai;
}
String TerrainEntity::getAI() {
    return ai;
}

// --

void TerrainEntity::setLife(double life) {
    this->life = life;
}
double TerrainEntity::getLife() {
    return life;
}
void TerrainEntity::setLifeMax(double lifemax) {
    this->lifemax = lifemax;
}
double TerrainEntity::getLifeMax() {
    return lifemax;
}
void TerrainEntity::setArmour(double armour) {
    this->armour = armour;
}
double TerrainEntity::getArmour() {
    return armour;
}

void TerrainEntity::setAerial(bool aerial) {
    this->aerial = aerial;
}
bool TerrainEntity::getAerial() {
    return aerial;
}
void TerrainEntity::setCamo(bool camo) {
    this->camo = camo;
}
bool TerrainEntity::getCamo() {
    return camo;
}