class_name Game extends Node3D

var team1:Team = Team.new();
var team2:Team = Team.new();
var playerTeam:Team = team1;

var mode = 0;
const modeNormal = 0; # no current action
const modeBuild = 1; # build new base towers / units
const modeEdit = 2; # upgrade / edit parameters
const modeResearch = 3; # research tab

var heldItem:Node3D;

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if(mode == modeBuild && heldItem != null):
		#print("mode build")
		var mouse = getMouseWorldPos();
		heldItem.position.x = mouse.x
		heldItem.position.y = 0
		heldItem.position.z = mouse.z
		if(Input.is_action_just_pressed("leftClick")):
			#print("placed turret at: ", mouse)
			remove_child(heldItem)
			get_node("Team1/Towers").add_child(heldItem)
			heldItem.active = true
			mode = modeNormal
			heldItem = null;
	
	pass


func _on_control_my_signal(extra_arg_0):
	print("GAME ON SIGNAL");
	pass # Replace with function body.



func getMouseWorldPos():
	var mouse_position = get_viewport().get_mouse_position();
	var pos = Vector3.ZERO;
	var cam = get_node("/root/Game/Camera3D") as Camera3D;
	var rayparam = PhysicsRayQueryParameters3D.new();
	var space_state = get_world_3d().direct_space_state;
	
	var rayOrigin = cam.project_ray_origin(mouse_position);
	var rayTarget = rayOrigin + cam.project_ray_normal(mouse_position) * 1000;
	rayparam.from = rayOrigin;
	rayparam.to = rayTarget;
	
	var intersection = space_state.intersect_ray(rayparam) as Dictionary;
	if not intersection.is_empty():
		pos = intersection.position;
	return pos;
