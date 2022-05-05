class_name GameGD extends Game

var team1:Team = Team.new(0);
var team2:Team = Team.new(1);
# current player on this client
var playerTeam:Team = team1;

var mode = 0;
const modeNormal = 0; # no current action
const modeBuild = 1; # build new base towers / units
const modeEdit = 2; # upgrade / edit parameters
const modeResearch = 3; # research tab

var heldItem:Node3D;
#var AI:PlayerAI = null;

var goldGenTime = 0;

# Called when the node enters the scene tree for the first time.
func _ready():
	#$Team2/Towers/TowerGun2.queue_free()
	#AI = PlayerAI.new();
	#add_child(AI);
	
	if(false): 
		$AI.queue_free()
	pass

func getTeam(team: int):
	if(team == 0): return team1;
	elif(team == 1): return team2;
	
func otherTeamGD(team: int):
	if(team == 0): return team2;
	elif(team == 1): return team1;
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	#if(AI != null):
		#print("ai not null")
	#	AI._process(delta)
	if(mode == modeBuild && heldItem != null):
		#print("mode build")
		var mouse = getMouseWorldPos();
		heldItem.position.x = mouse.x
		heldItem.position.y = 0
		heldItem.position.z = mouse.z
		if(Input.is_action_just_pressed("leftClick")):
			placeTower();
			
	# gold gen +5 per second for test
	goldGenTime += delta;
	if(goldGenTime > 1):
		team1.gold += 5;
		team2.gold += 5;
		goldGenTime = 0;
		
	pass


static func delete_children(node):
	for n in node.get_children():
		node.remove_child(n)
		n.queue_free()

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


func buildTower(team: Team, towerName: String):
	var item = load("res://data/towers/"+towerName+".tscn").instantiate()
	var t = team.team;
	item.data.setTeam(t);
	item.team = t;
	if(team == playerTeam):
		# put tower in held item temporarily for placing position
		mode = modeBuild;
		heldItem = item;
		add_child(item);
		return item;
	else:
		# add tower directly to team 2 towers
		get_node("Team2/Towers").add_child(item)
		item.active = true;
		team.gold -= item.data.getPrice();
		team.towers.push_back(item);
		return item;

func placeTower():
	#print("placed turret at: ", mouse)
	remove_child(heldItem);
	get_node("Team1/Towers").add_child(heldItem);
	playerTeam.gold -= heldItem.data.getPrice();
	playerTeam.towers.push_back(heldItem);
	heldItem.active = true;
	mode = modeNormal;
	heldItem = null;
	pass

func buyUnits(team: Team, towerSource: Tower, unitName: String):
	var path = get_node("Map/Path3D") as Path3D;
	var unit = load("res://models/"+unitName+".tscn").instantiate();
	var follow = PathFollow3D.new();
	follow.loop = false;
	unit.data.setTeam(team.team);
	team.gold -= unit.data.getPrice();
	unit.active = true;
	follow.add_child(unit);
	path.add_child(follow);
	if(towerSource != null):
		print("buy units from tower: ", towerSource)
	pass
