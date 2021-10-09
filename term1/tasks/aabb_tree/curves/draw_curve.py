import matplotlib.pyplot as plt
from optparse import OptionParser
from xml.dom import minidom
#from svg.path import parse_path, Path, Line, QuadraticBezier, CubicBezier, Arc
import sys

array = []
with open(sys.argv[1]) as f:
	for line in f:
		strings = line.split()
		for i in range(len(strings))[::2]:
			array.append([float(strings[i]),  float(strings[i+1])])


if len(sys.argv) > 2:
	array2 = []
	with open(sys.argv[2]) as f:
		for line in f:
			strings = line.split()
			for i in range(len(strings))[::2]:
				array2.append([float(strings[i]),  float(strings[i+1])])

plt.plot(*zip(*array))
if len(sys.argv) > 2:
	plt.plot(*zip(*array2))
plt.show()
