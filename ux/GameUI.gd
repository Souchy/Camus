extends Control

var game:Game;

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(game == null):
		game = get_node("/root/Game");
		
	# Build options
	var btns = get_node("BuildButtons").get_children(false);
	for n in btns:
		var b := n as Button;
		#print("btn name: ", b.name)
		
	# Edit / Upgrade options
	
	pass



func _on_control_resized():
	print("Resizing: ", get_viewport_rect().size)
	pass # Replace with function body.


# one of the new tower button, just temporary test
func _on_button_pressed():
	#print("button pressed")
	game.mode = game.modeBuild;
	var item = load("res://towers/TowerGun.tscn").instantiate()
	game.heldItem = item;
	game.add_child(item);
	pass # Replace with function body.



func _on_button_2_pressed():
	#print("button pressed")
	game.mode = game.modeBuild;
	var item = load("res://towers/Gun360.tscn").instantiate()
	game.heldItem = item;
	game.add_child(item);
	pass # Replace with function body.
