extends Node3D
# 1st step: create a line from point A to point B
# 2: segment the line and apply the distortion to the cut points for each scale
# 3: create mesh from point A to point B, following the segments
# 4: a random points, create a new branch with the same algorithm with a random destination of a random length
# 5: shaders/animation:
# 	5.1: have a little bit of vertex shader distortion
# 	5.2: have a little bit of blur and bloom
# 	5.2: have a little bit of thickness modulation

# each scale / units distance between each point on the line
var scales = [2, 0.5, 0.1, 0.02]
# distortion for each scale
var distortions = [0.5, 0.1, 0.02, 0.004]
# start and end point
var start = Vector3(0,10,0)
var end = Vector3(0,0,0)
# random
var rnd: RandomNumberGenerator = RandomNumberGenerator.new();
var noise = OpenSimplexNoise.new()

var meshes = []

func _ready():
	# Configure
	noise.seed = randi()
	noise.octaves = 1
	noise.period = 10.0
	noise.persistence = 0.8
	#print("cross 1: ", start.cross(end))
	#print("cross 2: ", end.cross(start))
	var points:Array = segmentate(start, end, 0)
	points.push_front(start);
	points.push_back(end);
	meshes = toMesh(points);
	for m in meshes:
		add_child(m);
	pass 

func _process(delta):
	noise.seed = randi()
	for m in meshes:
		m.position.x = noise.get_noise_3d(m.position.x, m.position.y, m.position.z) * delta
		m.position.z = noise.get_noise_3d(m.position.x, m.position.y, m.position.z) * delta
	pass

func segmentate(a:Vector3, b:Vector3, scale:float):
	var diff:Vector3 = b - a;
	var normalVector = (end - start).normalized();
	var length:float = diff.length();
	var numberOfPoints:float = floor(length / scales[scale]);
	var points = [];
	for i in range(1, numberOfPoints):
		var point:Vector3 = a + i * (diff / numberOfPoints);
		
		# represent the normal vector as (0,1,0), then translate on x and z
		var distortionX:float = rnd.randf() * distortions[scale] * randomSignum();
		var distortionZ:float = rnd.randf() * distortions[scale] * randomSignum();
		var trans = Vector3(distortionX, 1, distortionZ);
		var transR = trans.reflect(point);
		point.x += noise.get_noise_3d(point.x, point.y, point.z); #trans.x;
		point.z += noise.get_noise_3d(point.x, point.y, point.z); #trans.z;
		
		
		points.push_back(point);
		print("point: ", printVector(point), "\ttrans: ", printVector(trans), "\t = ", printVector(transR));
	return points
	
func toMesh(points:Array):
	var meshes = []
	for p in points:
		var mesh = MeshInstance3D.new();
		var sphere: SphereMesh = SphereMesh.new();
		sphere.radius = 0.05;
		sphere.height = 0.1;
		mesh.mesh = sphere;
		mesh.position.x = p.x;
		mesh.position.y = p.y;
		mesh.position.z = p.z;
		meshes.push_back(mesh)
	return meshes;
	
func randomSignum():
	return rnd.randi_range(0, 1) * 2 - 1
	
func printVector(v: Vector3):
	return "(" + str(v.x).pad_decimals(2) + ", " + str(v.y).pad_decimals(2) + ", " + str(v.z).pad_decimals(2) + ")"
	pass
