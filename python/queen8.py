#!/usr/bin/python

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
    pools = [tuple(pool) for pool in args] * kwds.get('repeat', 1)
    result= [[]]
    for pool in pools:
        result = [x+[y] for x in result for y in pool if (x==[] or ((y not in x) and (y+1!=x[-1]) and (y-1!=x[-1])))]
    for prod in result:
        yield tuple(prod)
    
def verify(coord):
    for a, b in GetComb(coord, 2):
        if(a[0]-a[1]==b[0]-b[1] or
           a[0]+a[1]==b[0]+b[1]):
            return False
    return True

def PrintQ(result):
    for res in result:
        print ''
        for i in range(8):
            for j in range(8):
                if j==res[i]:
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
    print len(result)
    PrintQ(result[:2])

print len(list(GetProduct(range(8), repeat=8)))
queen8()

