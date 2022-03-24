class_name Tower extends Node3D

# this is for debug with pre-placed towers
@export var team: int = 0
@onready var game:Game = get_node("/root/Game");
# this is actual data of the tower
var data:DataTower = DataTower.new();
var active = false;
var enemiesInArea = [];
var attackCooldown = 0;
var soundPath = "G:/Assets/pack/kenney/kenney_impactsounds/Audio/footstep_carpet_000.ogg";

var mode = modeFirst;
const modeFirst = 0;
const modeLast = 1;
const modeHighestHp = 2;
const modeLowestHp = 3;

# Called when the node enters the scene tree for the first time.
func _ready():
	data.team = team;
	$HealthBar.setTeam(data.team);
	data.update.connect($HealthBar.update);
	$AudioStreamPlayer3D.stream.loop = false;
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	#if(game.mode == game.modeNormal && Input.is_action_just_pressed("leftClick")):
		#shoot();
	if(enemiesInArea.size() > 0):
		var target = turn();
		attackCooldown += delta;
		if(attackCooldown >= data.attackTime):
			attackCooldown = 0;
			shoot(target);
	pass
	
func _physics_process(delta):
	pass

func shoot(target):
	var bullet = load("res://models/Bullet.tscn").instantiate()
	bullet.set_name("bullet")
	bullet.max_time_s = data.bullet_time_s
	bullet.position.x = self.position.x
	bullet.position.z = self.position.z
	bullet.direction = get_node("Head").rotation
	bullet.data.explodes = true
	bullet.data.team = data.team;
	bullet.target = target;
	#print("tower shoot: ", target)
	$Bullets.add_child(bullet)
	#$AudioStreamPlayer3D.play();
	#print("Tower %s new bullet area: %s" % [self, bullet.get_node("Area3D")])
	#print("tower gun left click: ", str(bullet.direction))
	pass

func upgrade():
	pass
	
func setStrategy():
	pass
	
func turn():
	var select = enemiesInArea.front();
	if(mode != modeFirst):
		for e in enemiesInArea:
			if(mode == modeLowestHp && e.data.life < select.data.life):
				select = e
			if(mode == modeHighestHp && e.data.life > select.data.life):
				select = e
			if(mode == modeLast):
				select = e
	#print("look at: ", select.get_parent().unit_offset)
	$Head.look_at(select.global_transform.origin);
	return select;

func death():
	# give money to killer, 
	# remove this from the list of towers or smth etc
	game.otherTeam(data.team).gold += self.data.bounty;
	queue_free()
	pass

# Max range / enemy detection range
func _on_area_3d_max_area_entered(area:Area3D):
#	if(not self.is_ancestor_of(area)):
#		print("Tower %s area entered: %s" % [self, area])
	#var thing = area.get_parent();
	#if(thing is Unit && thing.data.team != self.data.team):
	#	$Head.look_at(thing.position);
	var entity = area.get_parent();
	if(entity.active == true && entity is Unit && entity.data.team != self.data.team):
		enemiesInArea.append(entity);
	pass 
func _on_area_3d_max_area_exited(area):
#	if(!self.is_ancestor_of(area)):
#		print("Tower %s area exited: %s" % [self, area])
	var entity = area.get_parent();
	if(entity.active == true && entity is Unit && entity.data.team != self.data.team):
		enemiesInArea.erase(entity)
	pass 

# Min range / tower collision / tower selection
func _on_area_3d_min_area_entered(area):
	pass 
func _on_area_3d_min_area_exited(area):
	pass 
# Mouse selection
func _on_area_3d_min_mouse_entered():
	print("Tower mouse entered: ")
	pass 
func _on_area_3d_min_mouse_exited():
	pass 
func _on_area_3d_min_input_event(camera, event, position, normal, shape_idx):
	print("Tower mouse event: ", event)
	pass 





