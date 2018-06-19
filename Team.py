import Player

## TEAM CLASS ##
class Team(object):
	n_teams = 0
	def __init__(self, name, letter, players):
		# str name: team name
		# str letter: team letter
		# Players[] players: player lineup
		self.name = name;
		self.letter = letter
		self.lineup = players
		self.playing = players[:4]
		# all float
		self.ppg = 0
		self.ppb = 0
		self.pn = 0
		self.gn = 0
		self.prate = 0
		self.stddev_ppg = 0
		# all int
		self.powers = 0
		self.tu = 0
		self.negs = 0
		self.tuh = 0
		self.gp = 0
		self.b_heard = 0
		self.b_points = 0

	def get_top_scorer(self):
		# return top scorer in lineup
		return max(self.lineup, key=Player.get_ppg)

	def rename(self, name, letter):
		# rename team
		self.name = name
		self.letter = letter

	def calc_ppb(self):
		# recalculate ppb
		self.ppb = self.b_points / self.b_heard if self.b_heard != 0 else 0

	def update_stats(self):
		# recalculate all calculated stats
		self.ppg = ((15*self.powers) + (10*self.tu) - (5*self.negs)) / (self.tuh / 20)
		self.prate = self.powers / self.tu + self.powers if self.tu + self.powers != 0 else 0
		self.pn = self.powers / self.negs if self.negs != 0 else math.inf
		self.gn = (self.powers + self.tu) / self.negs if self.negs != 0 else math.inf
		self.calc_ppb()

	def add_players(players):
		# add players to lineup
		self.lineup.extend(players)

	def remove_players(players):
		# remove players from lineup
		for player in players:
			if player in self.lineup:
				self.lineup.remove(players)

	def make_subs(leaving, entering):
		# PRECONDITION
		assert(len(leaving) == len(entering)) 
		for player in leaving:
			assert(player in self.playing)
		# END PRECONDITION
		for i in range(len(leaving)):
			self.playing.remove(leaving[i])
			self.playing.append(entering[i])

	def add_tournaments(tournaments):
		self.tournaments.extend(tournament)

