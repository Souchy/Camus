class_name Base extends Node3D

@onready var constants = get_node("/root/GameConstants");

@export var team: int = 0
@onready var game:Game = get_node("/root/Game");
@onready var data:Team = game.getTeam(team);
var active = true;

# Called when the node enters the scene tree for the first time.
func _ready():
	#var mat = ($Roof as MeshInstance3D).get_surface_override_material(0) as StandardMaterial3D;
	var mat = StandardMaterial3D.new();
	($Roof as MeshInstance3D).set_surface_override_material(0, mat);
	mat.albedo_color = constants.getTeamColor(team);
	
	$HealthBar.setTeam(team);
	data.update.connect($HealthBar.update);
	#print("base: ", constants.getTeamColor(team), " ", mat);
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	#print("base: ", constants.getTeamColor(team));
	#var mat = ($Roof as MeshInstance3D).get_surface_override_material(0) as StandardMaterial3D;
	#mat.albedo_color = constants.getTeamColor(team);
	pass

func death():
	# gameover
	queue_free()
	pass;
