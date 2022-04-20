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
	
	string name;
	int price;	// $ cost to buy
	int bounty; // $ gain when killed
	string ai;  // aggressive, defensive, builder, first/last/strong/weak/close

	double life;
	double lifemax;
	double armour;
	bool aerial;
	bool camo;

	double attackDamage;
	double attackTime; // how much time between attacks
	double bulletTime; // how long a bullet lives
	double penetration;
	double range;
	bool antiAerial;
	bool antiCamo;


public:
	EntityData();
	~EntityData();
	//void setData(const TowerData& data);
	//TowerData getData() const;

	void signal_update();
	void test();

	void setTeam(int team);
	int getTeam();
	void setName(string name);
	string getName();
	void setPrice(int price);
	int getPrice();
	void setBounty(int bounty);
	int getBounty();
	void setAI(string ai);
	string getAI();

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