
八皇后问题

八皇后问题：将八个皇后摆在一个8x8的棋盘上。互相之间不能攻击。（任意两个皇后不能在同一横排，竖排和与对角线平行的斜线上）
这个问题很简单，聪明的呆呆已经破解了。
<PLACEHOLDER:img>

但是，还有其他的解。一共92个。（xu
我们可以使用计算机帮助我们解决这个问题。（smile

1. brute force
使用电子计算机，这个问题就很简单了。
我们暴力破解就行了。
遍历所有可能的摆放方式，然后一一验证是否合乎要求。
最后就得到了所有的解。
让我想想,
每个皇后有8X8=64个位置可以放。8个皇后一共64^8=281 4749 7671 0656种可能的布局。
281兆，好像有点太多了。
让我想想，
每个位置只能放一个棋子，这样第一个人有64个可能的位置，第二个人就只有63个格子可以选了，
最后一个朋友有64-8+1=57个选择。
这样的话可能的布局就只有64x63x62x...x57= 178 4629 8763 7760
不过有可能两次选择选到相同的8个位置，但是选择的顺序不同。
8个元素可能的排列有8x7x6x5x4x3x2x1= 40320 种
在64个格子中选出8个来的选法178462987637760/40320=44 2616 5368种。
（组合公式Crn=n!/r!/(n-r)!, 排列公式Arn=n!/(n-r)!)
只有44亿了！好像还是有点太多了。
让我想想。
任意两个皇后不能在同一排。可以肯定每一排有且只有一个皇后。
我们只需要在每一排中选一列就行了。
这样只有8^8= 1677 7216 种选择了。
还能再少点吗。
任意两个皇后不能在同一列，怎么去掉这样的情况呢。
>>> def GetProduct(*args, **kwds):
        pools = [tuple(pool) for pool in args] * kwds.get('repeat', 1)
        result= [[]]
        for pool in pools:
            result = [x+[y] for x in result for y in pool if y not in x]
        for prod in result:
            yield tuple(prod)
    print len(list(GetProduct(range(8), repeat=8)))
>>> 40320
现在只剩下40320种情况了，可以接受一一遍历了。
还能再少点吗。
我们还可以去掉多一些情况，一个皇后周围的八格都是不可以放其他皇后的。
所以相邻两排的皇后所在的列数一定不相邻。
>>> result = [x+[y] for x in result for y in pool if (x==[] or ((y not in x) and (y+1!=x[-1]) and (y-1!=x[-1])))]
现在只有5242种情况了。
既然都到这了，还能再少点!
>>> def Check(x, y):
        if y in x:
            return False
        n = len(x)
        for i in range(1,n+1):
            if y-i==x[n-i] or y+i==x[n-i]:
                return Flase
        return True
>>> result = [x+[y] for x in result for y in pool if (x==[] or Check(x, y))]
现在每次在新的一排寻找可用的列的时候，我们排除了所有非法的情况。
最后我们愉快的得到了92个解。（smile

2. recurse
递归的解法。




