#! /usr/bin/python

import copy
import re
import numpy
from numpy import array
from scipy.sparse import coo_matrix
from scipy.sparse.linalg import spsolve
from itertools import combinations

class Cell(object):
    def __init__(self, x, y, cost, layer):
        self.x = x
        self.y = y
        self.cost = cost    # -1 for blocked
        self.layer = layer  # layer 1 or 2

class Net(object):
    def __init__(self, id, pin1, pin2):
        self.id = id
        self.pin1 = pin1
        self.pin2 = pin2

class Grid(object):
    def __init__(self, x_size, y_size, bend_penalty, via_penalty):
        self.x_size = x_size
        self.y_size = y_size
        self.b_penalty = bend_penalty
        self.v_penalty = via_penalty
        self.cells = []
        
    def addCell(self, cell):
        self.cells.append(cell)

    def __repr__(self):
        return 'this is a gird %s x %s' % (self.x_size, self.y_size)


class Router(object):
    def __init__(self):
        self.nets = []
        self.grid = 'PLACERHOLDER'

    def InputParser(self):
        '''get the grid and nets from file'''
        fh = open('bench1.grid')   # no comment for parsing!!!
        first_line = fh.readline()
        pattern = re.compile("(\d+) (\d+) (\d+) (\d+)")    # X gridsize Y gridsize BendPenalty ViaPenalty
        match = pattern.search(first_line)
        (x_size, y_size, b_penalty, v_penalty) = match.groups()
        grid = Grid(x_size, y_size, b_penalty, v_penalty)
        pattern = re.compile("(\d+)")
        for layer in [1,2]:
            for line_cnt in range(int(y_size)):
                line = fh.readline()
                all_lst = pattern.findall(line)
                for column_cnt in range(len(all_lst)):
                    cost = all_lst[column_cnt]
                    cell = Cell(line_cnt, column_cnt, cost, layer)
                    grid.addCell(cell)
        self.grid = grid
        fh = open('bench1.nl')
        first_line = fh.readline()
        pattern = re.compile("(\d+)")
        match = pattern.search(first_line)
        (nets_num,) = match.groups()
        for line_cnt in range(int(nets_num)):
            line = fh.readline()
            all_lst = pattern.findall(line)
            (net_id, layer1, x1, y1, layer2, x2, y2) = all_lst
            pin1 = Cell(x1, y1, 0, layer1)
            pin2 = Cell(x2, y2, 0, layer2)
            net = Net(id, pin1, pin2)
            self.nets.append(net)
        fh.close()


if __name__ == '__main__':
    my_router = Router()
    my_router.InputParser()
    print my_router.nets
    print my_router.grid

