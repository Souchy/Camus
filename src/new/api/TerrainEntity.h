#pragma once

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
using namespace godot;

#include <string>
#include "Entity.h"
using namespace std;

class TerrainEntity : public Entity {
	GDCLASS(TerrainEntity, Entity);

protected:
	static void _bind_methods();

private:
    godot::Vector3 pos;

	int price = 15;	// $ cost to buy
	int bounty = 1; // $ gain when killed
	String ai;  // aggressive, defensive, builder, first/last/strong/weak/close
	
	double life = 3.0;
	double lifemax = life;
	double armour = 0.0;

    double movementSpeed = 1.0;
    bool aerial = false;
    bool camo = false;

public:
	TerrainEntity();
	~TerrainEntity();

	Vector3 getPos();

	void setPrice(int price);
	int getPrice();
	void setBounty(int bounty);
	int getBounty();
	void setAI(String ai);
	String getAI();

	void setLife(double life);
	double getLife();
	void setLifeMax(double lifemax);
	double getLifeMax();
	void setArmour(double armour);
	double getArmour();
	void setMovementSpeed(double movementSpeed);
	double getMovementSpeed();
	void setAerial(bool aerial);
	bool getAerial();
	void setCamo(bool camo);
	bool getCamo();
};