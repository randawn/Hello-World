#! /usr/bin/python

import itertools as it
from timeit import timeit
from random import randint

# combinations and permutations
def fact(x):
    """factorial or x: return x!"""
    if(x==0):
        return 1
    return x*fact(x-1)

def Arn(r, n):
    """num of permutation r from n"""
    ret = 1
    for t in range(n, n-r+1-1, -1):
        ret *= t
    return ret

def Crn(r, n):
    """get the num of combination r from n"""
    ret = 1
    if(r>n/2):
        return Crn(n-r, n)
    for t in range(n, n-r+1-1, -1):
        ret *= t
    return ret/fact(r)

def Crn_r(r, n):
    """recursively get Crn"""
    if(r==0 or r==n):
        return 1
    if(r>n/2):
        return Crn_ra(n-r, n)
    #return Crn_r(r-1, n-1) + Crn_r(r, n-1)
    return Crn_r(r-1, n-1)*n/r

#timeit()

# get the permutation

def Permute_first(seq):
    if len(seq)<=1:
        yield seq
    else:
        for perm in Permute_first(seq[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + seq[0:1] + perm[i:]

def Permute_last(seq):
    if len(seq)<=1:
        yield seq
    else:
        for perm in Permute_last(seq[:-1]):
            for i in range(len(perm)+1):
                yield perm[:i] + seq[0:1] + perm[i:]

def Permute_r(seq, n=None):
    """backtracking: pick everyone from the seq, then permute the left n-1.
    need 2N! changes"""
    if(n==None):
        n = len(seq)
    if(n==0):
        yield seq
    for i in range(n):
        seq[i], seq[n-1] = seq[n-1], seq[i]
        for s in Permute_r(seq, n-1):
            yield s
        seq[i], seq[n-1] = seq[n-1], seq[i]

def Permute_Heap(seq, n=None):
    """one swap per recurse"""
    if(n==None):
        n = len(seq)
    if n==1:
        yield seq
    for i in range(n):
        for s in Permute_Heap(seq, n-1):
            yield s
        if n&0x1==0: # even
            seq[i], seq[n-1] = seq[n-1], seq[i]
        else:        # odd
            seq[0], seq[n-1] = seq[n-1], seq[0]

def Permute_jt(seq):
    """johnson trotter: plain changes
    seq must be sorted""" 
    pass

def Permute_L(seq):
    """Lexicogrphic
    seq must be sorted""" 
    for k in range(len(seq)-1-1, -1, -1):
        if seq[k]<seq[k+1]:
            break
    else:
        yield seq
    for l in range(len(seq)-1, k, -1):
        if seq[k]<seq[l]:
            seq[k], seq[l] = seq[l], seq[k]
            yield seq
            seq = seq[:k+1] + seq[:k:-1]
            for s in Permute_L(seq):
                yield s
            break

def Permute(seq):
    """python build in"""
    n = len(seq)
    r = n
    indices = range(n)
    cycles = range(n, n-r, -1)
    yield [seq[i] for i in indices[:r]]
    while n:
        for i in reversed(range(r)):
            cycles[i] -= 1
            if cycles[i]==0:
                indices[i:] = indices[i+1:] + indices[i:i+1]
                cycles[i] = n - i
            else:
                j = cycles[i]
                indices[i], indices[-j] = indices[-j], indices[i]
                yield [seq[i] for i in indices[:r]]
                break
        else:
            return

# itertools.permutation
def Permute_it():
    pass

print list(Permute('ABCD'))

