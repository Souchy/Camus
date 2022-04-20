#include "Tower.h"
#include "EntityData.h"
#include "Unit.h"
#include "Projectile.h"
#include "../ux/HealthBar.h"

#include <godot_cpp/classes/sprite3d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/area3d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
using namespace godot;


void Tower::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_ready"), &Tower::_ready);
	ClassDB::bind_method(D_METHOD("_process"), &Tower::_process);

	ClassDB::bind_method(D_METHOD("getData"), &Tower::getData);
	ClassDB::bind_method(D_METHOD("setData", "data"), &Tower::setData);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data"), "setData", "getData");
	

	//ClassDB::bind_method(D_METHOD("shoot", "target"), &Tower::shoot);
	ClassDB::bind_method(D_METHOD("turn"), &Tower::turn);
	ClassDB::bind_method(D_METHOD("death"), &Tower::death);
	//ClassDB::bind_method(D_METHOD("_on_area_3d_max_area_entered", "area"), &Tower::_on_area_3d_max_area_entered);
	//ClassDB::bind_method(D_METHOD("_on_area_3d_max_area_exited", "area"), &Tower::_on_area_3d_max_area_exited);

	BIND_ENUM_CONSTANT(BasicTower);
	BIND_ENUM_CONSTANT(ShotgunTower);
	BIND_ENUM_CONSTANT(CannonTower);
	BIND_ENUM_CONSTANT(SpinningTower);
	BIND_ENUM_CONSTANT(SpreadTower);
}

Tower::Tower() {
	UtilityFunctions::print("Tower Constructor.");
}
Tower::~Tower() {
	UtilityFunctions::print("Tower Destructor.");
}

void Tower::setData(const Ref<EntityData>& dat) {
	this->data = dat;
}
Ref<EntityData> Tower::getData() const {
	return data;
}


void Tower::_ready() {
	// todo : 
	//ResourceLoader* loader = ResourceLoader::get_singleton();
	//loader->load("res://data/towers.json");
	
	//data.team = team;
	//$AudioStreamPlayer3D.stream.loop = false;
	game = get_node<Game>("/root/Game");

	// get healthbar
	HealthBar* hb = get_node<HealthBar>("HealthBar");
	// set healthbar team and connect update signal
	hb->setTeam(getData()->getTeam());
	getData()->connect("update", Callable(hb, "update"));
}

void Tower::_process(float delta) {
	UtilityFunctions::print("Tower process %s", delta);
	
	if(enemiesInArea.size() > 0){
		Unit* target = turn();
		attackCooldown += delta;
		if(attackCooldown >= data->getAttackTime()){
			attackCooldown = 0;
			shoot(target);
		}
	}
}

void Tower::shoot(Unit* target) {
	//Ref<Resource> ref = ResourceLoader::get_singleton()->load("res://models/Bullet.tscn");
	//ref.instantiate();
	//Resource* res = ref.ptr();
	//Projectile* pp = res;

	Ref<PackedScene> s = ResourceLoader::get_singleton()->load("res://models/Bullet.tscn");
	Projectile* bullet = (Projectile*) s->instantiate(); // .ptr()->instantiate();
	
	//Ref<Projectile> bullet = ResourceLoader::get_singleton()->load("res://models/Bullet.tscn");
	//bullet.instantiate();
	bullet->set_name("bullet");
	bullet->max_time_s = data->getBulletTime();
	
	bullet->set_position(this->get_position());
	bullet->direction = get_node<Node3D>("Head")->get_rotation();

	bullet->data.team = this->data->getTeam(); //->setTeam(this->data->getTeam());
	bullet->data.explodes = true;
	bullet->target = target;
	//print("tower shoot: ", target)

	Node* bullets = get_node<Node>("Bullets");
	bullets->add_child(bullet);
	//bullets->add_child(dynamic_cast<Node3D*>(p));
	//$AudioStreamPlayer3D.play();
	//print("Tower %s new bullet area: %s" % [self, bullet.get_node("Area3D")])
	//print("tower gun left click: ", str(bullet.direction))
}

Unit* Tower::turn() {
	Unit* select = enemiesInArea.front();
	if(mode != modeFirst){
		for(Unit* e : enemiesInArea) {
			if(mode == modeLowestHp && e->getData()->getLife() < select->getData()->getLife()) {
				select = e;
			}
			if(mode == modeHighestHp && e->getData()->getLife() > select->getData()->getLife()) {
				select = e;
			}
			if(mode == modeLast){
				select = e;
			}
		}
	}
	//print("look at: ", select.get_parent().unit_offset)
	Node3D* head = get_node<Node3D>("Head");
	head->look_at(select->get_global_transform().origin);
	
	return select;
}

/*
void Tower::death() {
	// give money to killer, 
	// remove this from the list of towers or smth etc
	game->otherTeam(this->data->getTeam()).gold += this->data->getBounty();
	queue_free();
}
*/

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}
//template<typename Base, typename T>
//inline bool instanceof(const T *ptr) {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
//}

void Tower::_on_area_3d_max_area_entered(Area3D area) {
	Node* entity = area.get_parent();
	if(entity->get_class() == "Unit") { //instanceof<Unit>(entity)) {
		Unit* u = (Unit*) entity;
		if(u->getData()->getTeam() != this->getData()->getTeam()) {
			enemiesInArea.push_back(u);
			//entity.active == true && entity is Unit && entity.data.team != self.data.team){
			//enemiesInArea.append(entity);
		}
	}
}
void Tower::_on_area_3d_max_area_exited(Area3D area) {
	Node* entity = area.get_parent();
	if(entity->get_class() == "Unit") { //if(instanceof<Unit>(entity)) {
		Unit* u = (Unit*) entity;
		if(u->getData()->getTeam() != this->getData()->getTeam()) {
			enemiesInArea.remove(u);
			//if(entity.active == true && entity is Unit && entity.data.team != self.data.team):
			//enemiesInArea.erase(entity)
		}
	}
}

void Tower::death() {

}
