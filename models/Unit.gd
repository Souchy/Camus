class_name Unit extends Node3D

# this is for debug with pre-placed units
#@export var team: int = 0
@onready var game:Game = get_node("/root/Game");
# this is actual data of the unit
var data:DataUnit = DataUnit.new();
var active = false;
var time = 0;
var speed = 2;
var path: PathFollow3D;

var enemiesInArea = [];
var mode = modeFirst;
const modeFirst = 0;
const modeLast = 1;
const modeHighestHp = 2;
const modeLowestHp = 3;

# Called when the node enters the scene tree for the first time.
func _ready():
	#data.team = team;
	if(get_parent() is PathFollow3D):
		path = get_parent();
	else:
		queue_free()
		return
		
	$HealthBar.setTeam(data.team);
	data.update.connect($HealthBar.update);
	
	if(data.team != game.playerTeam.team):
		path.unit_offset = 1;
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	walk(delta)
	if(enemiesInArea.size() > 0):
		var target = turn(delta)
		time += delta;
		if(time >= data.attack):
			time = 0;
			attack(target);
	pass

func walk(delta):
	if(data.team == game.playerTeam.team):
		path.offset += delta * speed;
	else:
		path.offset -= delta * speed;
	pass
	
func turn(delta):
	var select = enemiesInArea.front();
	if(mode != modeFirst):
		for e in enemiesInArea:
			# always prioritize Base
			if(e is Base):
				select = e;
				break;
			if(mode == modeLowestHp && e.data.life < select.data.life):
				select = e
			if(mode == modeHighestHp && e.data.life > select.data.life):
				select = e
			if(mode == modeLast):
				select = e
	
	#print("look at: ", select)
	$Head.look_at(select.global_transform.origin);
	return select;

func attack(target):
	var bullet = load("res://models/Bullet.tscn").instantiate()
	bullet.set_name("bullet")
	bullet.max_time_s = data.bullet_time_s
	bullet.position.x = self.getPos().x
	bullet.position.z = self.getPos().z
	bullet.direction = get_node("Head").rotation
	bullet.data.explodes = true
	bullet.data.team = data.team;
	bullet.target = target;
	#print("unit shoot: ", target)
	$Bullets.add_child(bullet)
	pass
	
func getPos():
	return global_transform.origin;

func death():
	# give money to killer, 
	# remove this from the list of towers or smth etc
	game.otherTeam(data.team).gold += self.data.bounty;
	queue_free()
	pass


func _on_range_area_entered(area):
	var entity = area.get_parent();
	
	if(entity.active == true && entity.data.team != self.data.team):
		enemiesInArea.append(entity);
	pass # Replace with function body.

func _on_range_area_exited(area):
	var entity = area.get_parent();
	if(entity.active == true && entity.data.team != self.data.team):
		enemiesInArea.erase(entity)
	pass # Replace with function body.
