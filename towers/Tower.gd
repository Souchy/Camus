class_name Tower extends Node3D

var data:TowerData = TowerData.new();
var active = false;
var game:Game;

# Called when the node enters the scene tree for the first time.
func _ready():
	pass 

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(game == null):
		game = get_node("/root/Game");
	if(game.mode == game.modeNormal && Input.is_action_just_pressed("leftClick")):
		shoot();
	turn();
	pass
	
func _physics_process(delta):
	pass

func shoot():
	var bullet = load("res://fx/Bullet.tscn").instantiate()
	bullet.set_name("bullet")
	bullet.position.x = self.position.x;
	bullet.position.z = self.position.z;
	bullet.direction = get_node("Head").rotation;
	$Bullets.add_child(bullet)
	#print("Tower %s new bullet area: %s" % [self, bullet.get_node("Area3D")])
	#print("tower gun left click: ", str(bullet.direction))
	pass
	
func upgrade():
	pass
	
func setStrategy():
	pass
	
func turn():
	var pos = game.getMouseWorldPos();
	$Head.look_at(pos);
	pass


# Max range / enemy detection range
func _on_area_3d_max_area_entered(area:Area3D):
#	if(not self.is_ancestor_of(area)):
#		print("Tower %s area entered: %s" % [self, area])
	pass 
func _on_area_3d_max_area_exited(area):
#	if(!self.is_ancestor_of(area)):
#		print("Tower %s area exited: %s" % [self, area])
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





