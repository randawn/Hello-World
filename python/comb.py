
def GetComb(iterable, r):
    """Py builtin ?"""
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

def product(lol):
    ret = [[]]
    for l in lol:
        ret = [x+[y] for x in ret for y in l]
    for i in ret:
        yield tuple(i)

print list(product((range(3), (chr(x+ord('a')) for x in range(3)))))

