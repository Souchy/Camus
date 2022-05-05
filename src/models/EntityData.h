#pragma once

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>
using namespace godot;

#include <string>
using namespace std;


class EntityData : public RefCounted {
	GDCLASS(EntityData, RefCounted);

protected:
	static void _bind_methods();

private:
	int team;
	
	String name;
	int price = 15;	// $ cost to buy
	int bounty = 1; // $ gain when killed
	String ai;  // aggressive, defensive, builder, first/last/strong/weak/close

	double life = 3.0;
	double lifemax = life;
	double armour = 0.0;

	double attackDamage = 1.0;
	double attackTime = 0.5; // how much time between attacks
	double bulletTime = 1.0; // how long a bullet lives
	double penetration = 0;
	double range = 3.0;

	bool aerial = false;
	bool camo = false;
	bool antiAerial = false;
	bool antiCamo = false;


public:
	EntityData();
	~EntityData();
	//void setData(const TowerData& data);
	//TowerData getData() const;

	void signal_update();
	void test();

	void setTeam(int team);
	int getTeam();
	void setName(String name);
	String getName();
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
	void setAttackDamage(double attackDamage);
	double getAttackDamage();
	void setAttackTime(double attackTime);
	double getAttackTime();
	void setBulletTime(double bulletTime);
	double getBulletTime();
	void setPenetration(double penetration);
	double getPenetration();
	void setRange(double range);
	double getRange();

	void setAerial(bool aerial);
	bool getAerial();
	void setCamo(bool camo);
	bool getCamo();
	void setAntiAerial(bool antiAerial);
	bool getAntiAerial();
	void setAntiCamo(bool antiCamo);
	bool getAntiCamo();
};
