import matplotlib.pyplot as plt
from optparse import OptionParser
from xml.dom import minidom
from svg.path import parse_path, Path, Line, QuadraticBezier, CubicBezier, Arc


array = []
with open('contours.txt') as f:
    for line in f: # read rest of lines
    	print (line)
    	strings = line.split()
    	print (strings)
    	print (range(len(strings))[::2])
    	for i in range(len(strings))[::2]:
    		array.append([float(strings[i]),  float(strings[i+1])])


print (array)
plt.plot(*zip(*array))
plt.show()