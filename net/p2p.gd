extends Node

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


# ----------------------------
# server host on one of the clients (like warframe, cod..)

# ----------------------------
# peer-to-peer with an 
# 	http API server for :
# 		auth + matchmaking 
# 		+ data (gamedata + gamehistory)

	# smash bros and starcraft1 use peer to peer

	# count "disagreements" for each client
	# if a client has many disagreements, put him in the cheater's queue

	# send packets twice with a different SSL key so it's very hard to modify/replicate.
	# the receiving peer can wait until both packets are arrived and valid before accepting the action
	
	# Types of p2p:
		# 1 host on one client (need port forward?)
		# 1 server on every client (need port forward?)
		# 1 mediator server that just forwards the messages between peers
  
# ----------------------------
# UDP vs TCP

	# the only important packets are: 
		# buy_turret, upgrade_turret, buy_units, gameover
	# the rest is shooting, positioning, damaging..
	# when there's 200 towers and units shooting each other 10/s, and the screen is full, UDP is important 

	# TCP: starcraft2, terraria, 
	# UDP: league, r6, cod, 
