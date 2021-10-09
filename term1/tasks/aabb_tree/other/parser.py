__author__ = 'miryaha-va'

from optparse import OptionParser
from xml.dom import minidom
from svg.path import parse_path, Path, Line, QuadraticBezier, CubicBezier, Arc


def extract_attributes(element):
    """ Returns integer value "type" and bool flag "whole" """
    edge_type = int(0)
    if 'type' in element.attributes.keys():
        edge_type = element.attributes['type'].value
	
    rho = 0.0
    if 'rho' in element.attributes.keys():
        rho = element.attributes['rho'].value

    c1 = 0.0
    if 'c1' in element.attributes.keys():
        c1 = element.attributes['c1'].value

    c2 = 0.0
    if 'c2' in element.attributes.keys():
        c2 = element.attributes['c2'].value


    whole = complex("inf")
    if 'whole' in element.attributes.keys():
        s = element.attributes['whole'].value.split()
        if len(s) != 2:
            raise Exception, 'attribute "whole" have to be "%f %f"'
        else:
            whole = complex(float(s[0]), float(s[1]))
    return (int(edge_type), whole, rho, c1, c2)


def get_path_splitted(element, min_edge_size, begin, end):
    distance = abs(element.point(begin) - element.point(end))
    if distance < min_edge_size:
        return list(tuple([element.point(begin), element.point(end)]))
    else:
        middle = (begin + end) * 0.5
        left_list = get_path_splitted(element, min_edge_size, begin, middle)
        right_list = get_path_splitted(element, min_edge_size, middle, end)
        return left_list + right_list


def get_segments_splitted(min_edge_size, start_point, end_point):
    distance = abs(start_point - end_point)
    if distance < min_edge_size:
        return list(tuple([start_point, end_point]))
    else:
        middle = (start_point + end_point) * 0.5
        left_list = get_segments_splitted(min_edge_size, start_point, middle)
        right_list = get_segments_splitted(min_edge_size, middle, end_point)
        return left_list + right_list


def svg_path_to_segment_list(svg_path, min_edge_size):
    """ Returns list of tuples (start_point, end_point) """
    segments = list()
    i = 0
    for element in svg_path:
        i += 1
        print (i, "from", len(svg_path))
        #print (segments)
        if element.length() < min_edge_size:
            segments.append(tuple([element.point(0), element.point(1)]))
        else:
            points = get_path_splitted(element, min_edge_size, 0, 1)
            for index in range(len(points) / 2):
                segments.append(tuple([points[2 * index], points[2 * index + 1]]))
    return segments

def segment_to_segment_list(min_edge_size, start_point, end_point):
    """ Returns list of tuples (start_point, end_point) """
    segments = list()

    if abs(start_point - end_point) < min_edge_size:
        segments.append(tuple([start_point, end_point]))
    else:
        points = get_segments_splitted(min_edge_size, start_point, end_point)
        for index in range(len(points) / 2):
            segments.append(tuple([points[2 * index], points[2 * index + 1]]))
    return segments

def parse_paths(paths, min_edge_size):
    segments = []
    index = 0
    for path in paths:
        index += 1
        print str(float(index) / len(paths) * 100) + ' %'
        if 'd' not in path.attributes.keys():
            raise Exception, 'There is no attribute "d" in path element'
        svg_path = parse_path(path.attributes['d'].value)
        common_attributes = extract_attributes(path)
        print(svg_path)
        segments.append(tuple([svg_path_to_segment_list(svg_path, min_edge_size), common_attributes]))
    return segments


def parse_rects(rects, min_edge_size):
    segments = []
    index = 0
    for rect in rects:
        index += 1
        print str(float(index) / len(rects) * 100) + ' %'
        
        width = float(rect.attributes['width'].value)
        height = float(rect.attributes['height'].value)
        x = float(rect.attributes['x'].value)
        y = float(rect.attributes['y'].value)
        common_attributes = extract_attributes(rect)

        c0 = complex(x, y)
        c1 = complex(x + width, y)
        c2 = complex(x + width, y + height)
        c3 = complex(x, y + height)

        segments.append(tuple([segment_to_segment_list(min_edge_size, c0, c1) + \
                               segment_to_segment_list(min_edge_size, c1, c2) + \
                               segment_to_segment_list(min_edge_size, c2, c3) + \
                               segment_to_segment_list(min_edge_size, c3, c0), common_attributes]))
    return segments


def parse_circle(circles, min_edge_size):
    segments = []
    return segments


def parse_ellipses(ellipses, min_edge_size):
    segments = []
    return segments


def parse_lines(lines, min_edge_size):
    segments = []
    return segments


def parse_polylines(polylines, min_edge_size):
    segments = []
    return segments


def parse_polygons(polygons, min_edge_size):
    segments = []
    return segments


class PointsDict(object):
    def __init__(self, eps):
        self.points = list()
        self.eps = eps

    def get_number(self, point):
        for index in range(len(self.points)):
            if abs(point - self.points[index]) < self.eps:
                return index
        self.points.append(point)
        return len(self.points) - 1

    def write_points(self, f, shift):
        f.write(str(len(self.points)) + '\n')
        for point in self.points:
            if shift is None:
                f.write('{0} {1} '.format(point.real, -point.imag))
            else:
                f.write('{0} {1} '.format(point.real + shift.real, -point.imag - shift.imag))
        f.write('\n')


# Output file format:
# paths numbers
# foreach path ...
#   path type, segments number
#       foreach segment ...
#           start_point_index, end_point_index
# points number
#   foreach point ...
#        point.x point.y

def save_segmetns_to_file(filename, blocks, shift=None):
    paths_count = 0
    for block in blocks:
        for path in block:
            paths_count += 1

    pd = PointsDict(float(1e-2))

    path_index = 0
    with open(filename, 'w') as f:
        print filename
        f.write(str(paths_count) + '\n')
        for block in blocks:
            for path in block:
                #type
                path_index += 1
                print float(path_index) / paths_count * 100
                f.write(str(path[1][0]) + ' ')
                f.write(str(path[1][2]) + ' ')
                f.write(str(path[1][3]) + ' ')
                f.write(str(path[1][4]) + ' ')
                #segments count
                f.write(str(len(path[0])) + ' ')
                for segment in path[0]:
                    f.write('{0} {1} '.format(pd.get_number(segment[0]), pd.get_number(segment[1])))
                f.write('\n')
        pd.write_points(f, shift)


def parse_contours(filename, min_edge_size):
    xml_doc = minidom.parse(filename)
    g_elems = xml_doc.getElementsByTagName('g')

    for g_elem in g_elems:
        print (g_elem)
        #if g_elem.getAttribute('inkscape:label') == 'Contours':
        segments = []
        paths = g_elem.getElementsByTagName('path')   
        segments.append(parse_paths(paths, min_edge_size))
        save_segmetns_to_file('contours.txt', segments)


def parse_submeshes(filename, min_edge_size):
    xml_doc = minidom.parse(filename)
    g_elems = xml_doc.getElementsByTagName('g')

    for g_elem in g_elems:
        if g_elem.getAttribute('inkscape:label') == 'BackGround':
            segments = []
            paths = g_elem.getElementsByTagName('path')            
            segments.append(parse_paths(paths, min_edge_size))

            rects = g_elem.getElementsByTagName('rect')            
            segments.append(parse_rects(rects, min_edge_size))            
            save_segmetns_to_file('submeshes.txt', segments)


parser = OptionParser()
parser.add_option("-f", "--file", dest="filename",
                  help="write *.svg file FILE", metavar="FILE")

parser.add_option("-e", "--min_edge_size", dest="min_edge_size",
                  help="write *.svg file FILE", metavar="FILE")

(options, args) = parser.parse_args()
min_edge_size = float(options.min_edge_size)

parse_contours(options.filename, min_edge_size)
#parse_submeshes(options.filename, min_edge_size)
