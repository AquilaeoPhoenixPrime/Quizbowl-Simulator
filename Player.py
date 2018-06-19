import math

## PLAYER CLASS ##
class Player(object):
	n_players = 0
	
	def __init__(self, id, firstname, lastname):
		# constructor
		self.id = id
		self.firstname = firstname
		self.lastname = lastname
		self.tournaments = []
		self.powers = 0
		self.tu = 0
		self.negs = 0
		self.tuh = 0
		self.ppg = 0
		self.pn = 0
		self.gn = 0
		self.negrate = 0
		self.buzzrate = 0
		self.prate = 0
		self.gp = 0
		n_players += 1
	
	def update_stats():
		# update calculated stats
		# CALL AFTER MODIFYING STATS
		self.ppg = ((15*self.powers) + (10*self.tu) - (5*self.negs)) / (self.tuh / 20)
		self.prate = self.powers / self.tu + self.powers if self.tu + self.powers != 0 else 0
		self.pn = self.powers / self.negs if self.negs != 0 else math.inf
		self.gn = (self.powers + self.tu) / self.negs if self.negs != 0 else math.inf
		if self.negs + self.powers + self.tu != 0:
			self.negrate = self.negs / (self.negs + self.powers + self.tu)
		else:
			self.negrate = 0
		self.buzzrate = self.tuh + self.tuh
	
	def inc_powers(n=1):
		self.powers += n

	def set_powers(n):
		self.powers = n

	def inc_tu(n=1):
		self.tu += n

	def set_tu(n):
		self.tu = n

	def inc_negs(n=1):
		self.negs += n

	def set_negs(n):
		self.negs = n

	def inc_tuh(n=1):
		self.tuh += n

	def set_tuh(n):
		self.tuh = n

	def inc_gp(n=1):
		self.gp += n

	def set_gp(n):
		self.gp = n
	
	def get_id():
		return self.id

	def get_ppg():
		return self.ppg

	def get_prate():
		return self.prate

	def get_buzzrate(): 
		return self.buzzrate

	def get_negrate():
		return self.negrate