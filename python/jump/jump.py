from PIL import Image

im = Image.open('j00.jpg')
(w, h) = im.size
print w, h
scale = w/20.0
w_n = int(w/scale)
h_n = int(h/scale)
im = im.resize((w_n, h_n))

import numpy as np

print("w_n is %d h_n s %d" % (w_n, h_n))
# a point is 
# [r, g, b, x, y, visit, noise, cluster]
a_3d = np.zeros([w_n, h_n, 8], dtype=int)

for idx in np.ndindex(w_n, h_n):
    pix = im.getpixel(idx)
    pix = tuple(i/10*10 for i in pix)
    a_3d[idx[0], idx[1]] = idx + pix + (0, 0, 0)

#print a_3d

#for idx in np.ndindex(w_n, h_n):
#    im.putpixel(idx, tuple(a_3d[idx[0], idx[1]][:3]))

def DBSCAN(D, eps, MinPts):
    C = 0
    for idx in np.ndindex(w_n, h_n):
        P = D[idx[0], idx[1]]
        if P[5]:
            continue
        P[5] = 1
        NeighborLst = regionQuery(P, D, eps)
        if len(NeighborLst) < MinPts:
            P[6] = 1
        else:
            C = C+1
            P[7] = C
            for P_n in NeighborLst:
                if not P_n[5]:
                    P_n[5] = 1
                    NeighborLst_n = regionQuery(P_n, D, eps)
                    if len(NeighborLst_n) >= MinPts:
                        NeighborLst.extend(NeighborLst_n)   # DANGER!
                if not P_n[7]:
                    P_n[7] = C

def regionQuery(P, D, eps):
    P_o = P
    ret = []
    for idx in np.ndindex(w_n, h_n):
        P = D[idx[0], idx[1]]
        if distance(P_o[:5], P[:5]) < eps:
            ret.append(P)
    return ret
    
import math
def distance(P0, P1):
    """ Euclidean for now """
    coord = (P0[i]-P1[i] for i in range(len(P0)))
    pow2 = (x*x for x in coord)
    dis = math.sqrt(sum(pow2))
    return int(dis)
    
DBSCAN(a_3d, 17, 30)

for idx in np.ndindex(w_n, h_n):
    if a_3d[idx[0], idx[1]][7]==1:
        a_3d[idx[0], idx[1]][:3] = (255, 255, 255)
    elif a_3d[idx[0], idx[1]][7]==2:
        a_3d[idx[0], idx[1]][:3] = (0, 255, 0)
    elif a_3d[idx[0], idx[1]][7]==3:
        a_3d[idx[0], idx[1]][:3] = (0, 0, 255)
    elif a_3d[idx[0], idx[1]][7]==4:
        a_3d[idx[0], idx[1]][:3] = (255, 255, 0)
    elif a_3d[idx[0], idx[1]][7]==5:
        a_3d[idx[0], idx[1]][:3] = (255, 0, 255)
    elif a_3d[idx[0], idx[1]][7]==6:
        a_3d[idx[0], idx[1]][:3] = (0, 255, 255)
    elif a_3d[idx[0], idx[1]][7]==7:
        a_3d[idx[0], idx[1]][:3] = (0, 0, 0)
#    if a_3d[idx[0], idx[1]][7]==8:
    else:
        a_3d[idx[0], idx[1]][:3] = (255, 0, 0)
    im.putpixel(idx, tuple(a_3d[idx[0], idx[1]][:3]))

im.show()
