class_name Gun360 extends TowerGD

# Called when the node enters the scene tree for the first time.
#func _ready():
#	super._ready();
#	data.attack = 15;
#	data.range = 175;
#	#print("TowerGun ready")
#	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	super._process(delta)
#	get_tree().set_debug_collisions_hint(true) 
#	pass
	
func shoot(target):
	for i in range(8):
		var bullet = load("res://models/Bullet.tscn").instantiate()
		bullet.max_time_s = 0.2;
		bullet.set_name("bullet" + str(i))
		bullet.position.x = self.position.x;
		bullet.position.z = self.position.z;
		bullet.direction = get_node("Head").rotation;
		# cercle = 2PI, on a 8 cannons donc 2PI/8 = PI/4
		# on ajoute cette rotation fois le numéro du cannon
		bullet.direction.y += i * PI / 4;
		#print("i %s, dir %s" % [i, bullet.direction])
		$Bullets.add_child(bullet)
	pass



