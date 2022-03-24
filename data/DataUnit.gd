class_name DataUnit

func get_class(): return "DataUnit"
signal update

var name = "";
var team = 0;

var life = 3.0;
var lifemax = life;
var armour = 0;
var attack = 1.0;
var attackTime = 0.5;
var bullet_time_s = 1;
var penetration = 0;
var range = 3.0;
var flies = false;
var antiAeral = false;
var antiCamo = false;

var cost = 15;
var bounty = 1;

var ai = "aggressive"; # defensive, builder, 

