class_name UnitGD extends Unit

# this is for debug with pre-placed units
#@export var team: int = 0
@onready var game:Game = get_node("/root/Game");
# this is actual data of the unit
#var data:DataUnit = DataUnit.new();
var active = false;
var time = 0;
var speed = 2;
var path: PathFollow3D;

var enemiesInArea2 = [];
var mode = modeFirst;
const modeFirst = 0;
const modeLast = 1;
const modeHighestHp = 2;
const modeLowestHp = 3;

func _init():
	#print("UnitGD _init");
	data = EntityData.new();
	pass

# Called when the node enters the scene tree for the first time.
func _ready():
	#super._ready();
	#print("UnitGD ready");
	#data.team = team;
	if(get_parent() is PathFollow3D):
		path = get_parent();
	else:
		queue_free()
		return
		
	$HealthBar.setTeam(data.getTeam());
	data.update.connect($HealthBar.update);
	
	if(data.getTeam() != game.playerTeam.team):
		path.unit_offset = 1;
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	walk(delta)
	if(enemiesInArea2.size() > 0):
		#print("UnitGD process to turn");
		var target = turn(delta)
		time += delta;
		if(time >= data.getAttackTime()):
			time = 0;
			attack(target);
	pass

func walk(delta):
	if(data.getTeam() == game.playerTeam.team):
		path.offset += delta * speed;
	else:
		path.offset -= delta * speed;
	pass
	
func turn(delta):
	#print("UnitGD turn");
	var select = enemiesInArea2.front();
	if(mode != modeFirst):
		for e in enemiesInArea2:
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
	bullet.max_time_s = data.getBulletTime()
	bullet.position.x = self.getPos().x
	bullet.position.z = self.getPos().z
	bullet.direction = get_node("Head").rotation
	bullet.data.explodes = true
	bullet.data.team = data.getTeam();
	bullet.target = target;
	#print("unit shoot: ", target)
	$Bullets.add_child(bullet)
	pass
	
func getPos():
	return global_transform.origin;

func death():
	# give money to killer, 
	# remove this from the list of towers or smth etc
	game.otherTeamGD(data.getTeam()).gold += self.data.getBounty();
	queue_free()
	pass


func _on_range_area_entered(area):
	#print("UnitGD on range entered");
	#if(not self.is_ancestor_of(area)):
	#	print("Unit %s area entered: %s" % [self, area])
	var entity = area.get_parent();
	
	if(entity.active == true && entity.data.getTeam() != self.data.getTeam()):
		enemiesInArea2.append(entity);
	pass # Replace with function body.

func _on_range_area_exited(area):
	#print("UnitGD on range exited");
	var entity = area.get_parent();
	if(entity.active == true && entity.data.getTeam() != self.data.getTeam()):
		enemiesInArea2.erase(entity)
	pass # Replace with function body.
