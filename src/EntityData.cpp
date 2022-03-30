

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include "EntityData.h"
using namespace godot;



void EntityData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("getTeam"), &EntityData::getTeam);
	ClassDB::bind_method(D_METHOD("setTeam", "team"), &EntityData::setTeam);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "team"), "getTeam", "setTeam");

	ADD_GROUP("Test group", "group_");
	ADD_SUBGROUP("Test subgroup", "group_subgroup_");
}

EntityData::EntityData()
{
}

EntityData::~EntityData()
{
}


// --

void EntityData::setTeam(int team)
{
	this->team = team;
}

int EntityData::getTeam()
{
	return team;
}

void EntityData::setName(string name)
{
	this->name = name;
}

string EntityData::getName()
{
	return name;
}

void EntityData::setPrice(int price)
{
	this->price = price;
}

int EntityData::getPrice()
{
	return price;
}

void EntityData::setBounty(int bounty)
{
	this->bounty = bounty;
}

int EntityData::getBounty()
{
	return bounty;
}

void EntityData::setAI(string ai)
{
	this->ai = ai;
}

string EntityData::getAI()
{
	return ai;
}

// --

void EntityData::setLife(double life)
{
	this->life = life;
}

double EntityData::getLife()
{
	return life;
}

void EntityData::setLifeMax(double lifemax)
{
	this->lifemax = lifemax;
}

double EntityData::getLifeMax()
{
	return lifemax;
}

void EntityData::setArmour(double armour)
{
	this->armour = armour;
}

double EntityData::getArmour()
{
	return armour;
}

void EntityData::setAttackDamage(double attackDamage)
{
	this->attackDamage = attackDamage;
}

double EntityData::getAttackDamage()
{
	return attackDamage;
}

void EntityData::setAttackTime(double attackTime)
{
	this->attackTime = attackTime;
}

double EntityData::getAttackTime()
{
	return attackTime;
}

void EntityData::setBulletTime(double bulletTime)
{
	this->bulletTime = bulletTime;
}

double EntityData::getBulletTime()
{
	return bulletTime;
}

void EntityData::setPenetration(double penetration)
{
	this->penetration = penetration;
}

double EntityData::getPenetration()
{
	return penetration;
}

void EntityData::setRange(double range)
{
	this->range = range;
}

double EntityData::getRange()
{
	return range;
}


// --


void EntityData::setAerial(bool aerial)
{
	this->aerial = aerial;
}

bool EntityData::getAerial()
{
	return aerial;
}

void EntityData::setCamo(bool camo)
{
	this->camo = camo;
}

bool EntityData::getCamo()
{
	return camo;
}

void EntityData::setAntiAerial(bool antiAerial)
{
	this->antiAerial = antiAerial;
}

bool EntityData::getAntiAerial()
{
	return antiAerial;
}

void EntityData::setAntiCamo(bool antiCamo)
{
	this->antiCamo = antiCamo;
}

bool EntityData::getAntiCamo()
{
	return antiCamo;
}
