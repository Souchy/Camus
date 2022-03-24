class_name DataBullet

func get_class(): return "DataBullet"
signal update

var team = 0;

@export var damage: int = 1.0
@export var penetration: int = 0


@export var followsTarget: bool = false
@export var pierces: int = 0
@export var chains: int = 0
@export var explodes: bool = false

@export var explosionRadius: float = 1;
