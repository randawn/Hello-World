#!/usr/bin/python

from random import choice
NUM = 8

def GetComb(iterable, r):
    pool = tuple(iterable)
    n = len(pool)
    if r>n:
        return
    indices = list(range(r))
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i+n-r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)

def GetProduct(*args, **kwds):
    def Check(x, y):
        if y in x:
            return False
        n = len(x)
        for i in range(1,n+1):
            if y-i==x[n-i] or y+i==x[n-i]:
                return False
        return True
    pools = [tuple(pool) for pool in args] * kwds.get('repeat', 1)
    result= [[]]
    for pool in pools:
        result = [x+[y] for x in result for y in pool if Check(x, y)]
    for prod in result:
        yield tuple(prod)
    
def verify(coord):
    for a, b in GetComb(coord, 2):
        if(a[0]-a[1]==b[0]-b[1] or
           a[0]+a[1]==b[0]+b[1]):
            return False
    return True

def PrintQ(rows):
    for i in range(8):
        for j in range(8):
            if j==rows[i]:
                print 'x',
            else:
                print '0',
        print ''

def queen8():
    result = []
    for rows in GetProduct(range(8), repeat=8):
        coord = zip(range(8), rows)
        if(verify(coord)):
            result.append(rows)
    print "TOTAL", len(result)
    print "print rand 1"
    PrintQ(choice(result))

if __name__ == '__main__':
    queen8()

