extends Node

func getTeamColor(team: int):
	if(team == 0):
		return Color.DARK_RED;
	if(team == 1):
		return Color.DODGER_BLUE;
		
	return Color.DARK_RED;
	pass
