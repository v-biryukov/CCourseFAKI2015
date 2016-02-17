import random
from names import boy_names, girl_names
from surnames import surnames

min_year = 1900
max_year = 2100
max_playing_years = 40
positions = ['C', 'G', 'F']
universities = ["MIPT", "MIT", "Stanford", "MSU", "UCLA", "Oxford", "Cambridge", "Saint Petersburg State University", "Boston College", "Bauman Moscow State Technical University"]

N = 10000

f = open("gen_players.txt", 'w')

for i in range(N):
	name = ""
	if random.random() > 0.5:
		name = random.choice(boy_names)
	else:
		name = random.choice(girl_names)
	surname = random.choice(surnames)
	position = random.choice(positions)
	university = random.choice(universities)

	start_year = random.randint(min_year, max_year)
	end_year = random.randint(start_year, start_year + max_playing_years)
	f.write(surname)
	f.write(", ")
	f.write(name)
	f.write("\n")
	f.write(str(start_year))
	f.write(" - ")
	f.write(str(end_year))
	f.write(" ")
	f.write(position)
	f.write("\t")
	f.write(university)
	if i != N-1:
		f.write("\n")


f.close()