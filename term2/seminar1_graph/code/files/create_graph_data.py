import random
with open("russian_cities_names.txt") as f:
    cities_names = f.readlines()

cities_names = list(set([x.strip() for x in cities_names]))



min_dist = 10
max_dist = 200
N = len(cities_names)

cities = {}
for i in range(N):
	n_neigh = random.randint(0, 6) + 1
	cities[cities_names[i]] = []
	for j in range(n_neigh):
		ni = (i + 1 + random.randint(0, N-2)) % N
		cities[cities_names[i]].append((cities_names[ni], random.randint(0, max_dist-min_dist) + min_dist))



for i in range(N):
	for j in range(N):
		if i != j:
			for k in range(len(cities[cities_names[j]])):
				if cities_names[i] == cities[cities_names[j]][k][0]:
					is_connected = False
					for el in cities[cities_names[i]]:
						if el[0] == cities_names[j]:
							is_connected = True
					if not is_connected:
						cities[cities_names[i]].append((cities_names[j], cities[cities_names[j]][k][1]))




with open("graph.txt", 'w') as f:
	f.write(str(N) + "\n")
	for i in range(N):
		f.write(cities_names[i] + " " + str(len(cities[cities_names[i]])) + "\t")
		for j in range(len(cities[cities_names[i]])):
			f.write(cities[cities_names[i]][j][0] + " "+ str(cities[cities_names[i]][j][1]) + " ")
		f.write("\n")




