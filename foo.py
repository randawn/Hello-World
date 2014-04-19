#! /usr/bin/python

def AllSeq(seq):
    if (len(seq) == 1):
        return seq
    seqn = []
    for i in range(len(seq)):
        seqtmp = seq[:]
        (seqtmp[0],seqtmp[i]) = (seqtmp[i],seqtmp[0])
        seqn.append(seqtmp)
    return seqn
    #seq_return = []
    #for item in seqn:
    #    seq_return.append([item[0]] + AllSeq(item[1:]))
    #return seq_return

def GoldSeq(seq, pos=0):
    if pos == len(seq):
        yield seq
    for i in range(pos, len(seq)):
        arr = seq[:]
        #if (arr == seq):
        #    continue
        arr[pos], arr[i] = arr[i], arr[pos]
        for _ in GoldSeq(arr, pos+1): yield _
        arr[pos], arr[i] = arr[i], arr[pos]

def esspresoo():
    ret = []
    a = [1]*2 + [0]*4
    b = [1]*3 + [0]*3
    c = [1]*4 + [0]*2
    for x in [a, b, c]:
        for item in GoldSeq(x):
            stri = ''
            for i in item:
                stri += str(i)
            ret.append(stri)
    return ret


a = esspresoo()
b = set(a)
c = list(set(b))
c.sort()
#for i in c:
#    print i

def tobin(head,tail=''):
    if(head == 0):
        return '0' + tail
    if(head == 1):
        return '1' + tail
    else:
        return tobin(head/2,str(head%2) + tail)

for a in range(8):
    for b in range(8):
        s = (a*b) % 13
        print "%03s%03s%04s" % (tobin(a),tobin(b),tobin(s))

