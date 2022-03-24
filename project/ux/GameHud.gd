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
	$DebugLabels/lblFPS.text = "fps: " + str(Engine.get_frames_per_second());
	$lblGold.text = "gold: " + str(game.playerTeam.gold);
	pass



func _on_control_resized():
	print("Resizing: ", get_viewport_rect().size)
	pass # Replace with function body.


# one of the new tower button, just temporary test
func _on_button_pressed():
	game.buildTower(game.playerTeam, "TowerGun");

func _on_button_2_pressed():
	game.buildTower(game.playerTeam, "Gun360");


func _on_button_5_pressed():
	game.buyUnits(game.playerTeam, null, "Unit");
	pass # Replace with function body.
