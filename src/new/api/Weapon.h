#pragma once

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
using namespace godot;

#include <string>
#include "Entity.h"
#include "TerrainEntity.h"
using namespace std;


class Weapon : public Entity {
	GDCLASS(Weapon, Entity);

protected:
	static void _bind_methods();

private:
    int ammo = 1000000;
	double attackDamage = 1.0;
	double attackTime = 0.5; // how much time between attacks
	double penetration = 0;
	double range = 3.0;
	//double bulletTime = 1.0; // how long a bullet lives
    double bulletTravelTimeBonus; 

	bool antiAerial = false;
	bool antiCamo = false;

public:
	Weapon();
	~Weapon();

	void setAmmo(int ammo);
	int getAmmo();
	void setAttackDamage(double attackDamage);
	double getAttackDamage();
	void setAttackTime(double attackTime);
	double getAttackTime();
	void setPenetration(double penetration);
	double getPenetration();
	void setRange(double range);
	double getRange();
	void setBulletTravelTimeBonus(double bulletTravelTimeBonus);
	double getBulletTravelTimeBonus();

	void setAntiAerial(bool antiAerial);
	bool getAntiAerial();
	void setAntiCamo(bool antiCamo);
	bool getAntiCamo();

    // 
    void shoot(TerrainEntity source);
};