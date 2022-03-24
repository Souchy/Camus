class_name Bullet extends Node3D

var data: DataBullet = DataBullet.new();
var direction: Vector3 = Vector3(0,0,0);
var speed = 20.0;
var time = 0;
var max_time_s = 1;
var target = null;
var percentSeeking = 1;
var active = true;

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
	var wr = weakref(target);
	if (target == null || !wr.get_ref()):
		queue_free()
		return
	#position.x += -sin(direction.y) * speed * delta;
	#position.z += -cos(direction.y) * speed * delta;
	var pos;
	if(target is Unit):
		pos = target.getPos();
	else:
		pos = target.position;
	
	var diff = pos - position;
	diff = diff.normalized();
	diff *= percentSeeking;
	diff.x += (-sin(direction.y) * (1.0 - percentSeeking))
	diff.z += (-cos(direction.y) * (1.0 - percentSeeking))
	diff *= delta;
	diff *= speed;
	position += diff;
	
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	pass


func _on_area_3d_area_entered(area: Area3D):
	var parent = area.get_parent();
	# ignore l'area max qui sert de détection
	if(area.name == "Range"): 
		return
	# ignore collision with own team
	if(parent.data.team == data.team):
		return
	# do damage to towers and units
	if(parent is Unit || parent is Tower || parent is Base): 
		var target = parent.data;
		#print("bullet on diff team: %s, %s " % [target.team, data.team]);
		hit(target)
		if(data.chains > 0):
			hit(target);
			# ??? create an area3d that does damage to everything in its radius?
			pass
		elif(data.pierces > 0):
			data.pierces -= 1;
		else:
			queue_free();
	pass # Replace with function body.


# Target is either DataUnit or DataTower
func hit(target):
	#print("hit: ", target.get_class())
	damage(self.data, target);
	if(data.explodes):
		explosion()
	target.update.emit()
	#self.data.update.emit()
	pass


# Target is either DataUnit or DataTower, Bullet is DataBullet
func damage(bullet, target):
	var reduction = (target.armour - bullet.penetration);
	if(reduction < 0): 
		reduction = 0
	target.life -= (bullet.damage - reduction);
	pass

func explosion():
	# ??? create an area3d that does damage to everything in its radius?
	var explosion = Area3D.new();
	var explosionCollider = CollisionShape3D.new();
	var explosionShape = CylinderShape3D.new();
	explosion.add_child(explosionCollider);
	explosionCollider.shape = explosionShape;
	explosionShape.radius = self.data.explosionRadius;
	explosion.position = self.position;
	var areas = explosion.get_overlapping_areas();
	for a in areas:
		if(self.data.team != a.get_parent().data.team):
			damage(self.data, a.data)
	explosion.queue_free()
	pass
