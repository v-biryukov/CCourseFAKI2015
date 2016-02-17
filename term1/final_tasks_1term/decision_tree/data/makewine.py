
array = []
with open('winequality-white.csv') as f:
	f.readline()
	for line in f: # read rest of lines
		array.append([float(x) for x in line.split()])


f = open('wine.txt','w')

for i, el in enumerate(array):
	num = 0
	if el[num] > 8.0:
		f.write('veryhigh ')
	elif el[num] > 7.0:
		f.write('high ')
	elif el[num] > 6.0:
		f.write('medium ')
	elif el[num] > 5.0:
		f.write('low ')
	else:
		f.write('verylow ')


	num = 3
	if el[num] > 15.0:
		f.write('veryhigh ')
	elif el[num] > 10.0:
		f.write('high ')
	elif el[num] > 3.0:
		f.write('medium ')
	elif el[num] > 1.0:
		f.write('low ')
	else:
		f.write('verylow ')


	num = 7
	if el[num] > 1.0:
		f.write('veryhigh ')
	elif el[num] > 0.98:
		f.write('high ')
	elif el[num] > 0.995:
		f.write('medium ')
	elif el[num] > 0.993:
		f.write('low ')
	else:
		f.write('verylow ')


	#f.write(str(int(el[8])) + ' ')
	f.write(str(int(el[10])) + ' ')
	f.write(str(int(el[11])) + ' ')

	f.write('\n')



f.close()

