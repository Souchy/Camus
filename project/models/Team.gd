class_name Team

func get_class(): return "Team"
signal update

var name = "";
var team = 0;

var life = 20;
var lifemax = 20;
var armour = 0;

var gold = 100;
var units = [];
var towers = [];


func _init(id: int):
	self.team = id;
	pass
