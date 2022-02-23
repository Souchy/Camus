class_name TowerGun extends "Tower.gd"


# Called when the node enters the scene tree for the first time.
func _ready():
	super._ready();
	data.attack = 15;
	data.range = 175;
	#print("TowerGun ready")
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	super._process(delta)
	get_tree().set_debug_collisions_hint(true) 
	pass
	


