class_name Bullet extends Node3D

var direction: Vector3 = Vector3(0,0,0);
var speed = 15;
var time = 0;
var max_time_s = 10;

# Called when the node enters the scene tree for the first time.
func _ready():
	#print("new bullet area: ", get_node("Area3D"))
	pass # Replace with function body.
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	time += delta;
	if(time >= max_time_s):
		#print("delete bullet")
		queue_free()
		pass
	position.x += -sin(direction.y) * speed * delta;
	position.z += -cos(direction.y) * speed * delta;
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	pass
