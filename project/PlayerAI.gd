class_name PlayerAI extends Node

#var game:Game;
@onready var game:Game = get_node("/root/Game");
@onready var team:Team = game.team2;

var timerUnits = 0;

#func _init():
	#self.game = game; #game = get_node("/root/Game")
	#team = game.team2
#	pass

func _ready():
	#game = get_node("/root/Game")
	team = game.team2;
	pass

func _process(delta):
	if(game == null || team == null):
		game = get_node("/root/Game")
		team = game.team2;
	
	timerUnits += delta;
	if(timerUnits > 0):
		if(team.gold > 0):
			buyUnits()
			timerUnits = 0;
	
	if(team.gold >= 100):
		buyTower()
	#print("AI process")
	#if(team.towers.size() % 2 == 0):
	pass

func buyTower():
	#print("AI buy Tower")
	#var t = load("res://data/towers/TowerGun.tscn").instantiate();
	var tower = game.buildTower(team, "TowerGun");
	tower.position.x = -4.5 + team.towers.size();
	tower.position.y = 0;
	tower.position.z = -4.5;
	pass


func buyUnits():
	print("AI buy Units")
	game.buyUnits(team, null, "Unit");
	pass

func upgradeTower():
	pass
