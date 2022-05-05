extends Sprite3D

@onready var parent = get_parent();
@onready var data = parent.data;
@onready var constants = get_node("/root/GameConstants");

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func setTeam(team: int):
	modulate = constants.getTeamColor(team)
	pass

# source is the attacker player
func update():
	print("hp parent: ", parent.data.getLife())
	self.scale.x = parent.data.getLife() / parent.data.getLifeMax();
	#print("healthbar update: %s, %s " % [data.life, self.scale.x])
	if(parent.data.getLife() <= 0):
		parent.death()
	pass
