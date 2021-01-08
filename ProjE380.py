# # count of the number of spanning trees in an m by n grid:
# #
# #   product{a = 0 .. m - 1, b =  0 .. n - 1, (a * b > 0):
# #   2 * (2 - cos(a * pi / m) - cos(b * pi / n))} / (m * n)
# #
# # keep track of powers of 2 in its calculation and return
# # (m, e) where the count value is m * 2 ** e. 

# from math import pi, cos, log10, frexp, fmod

# def maze_count(m, n):
#   cm, cn = pi / m, pi / n
#   p = 1.0
#   p2 = 0
#   for a in range(m):
#     for b in range(n):
#       if a or b:
#         p *= 2.0 * (2.0 - cos(a * cm) - cos(b * cn))
#         while p < 0.5:
#           p *= 2.0
#           p2 -= 1
#         while p >= 2.0:
#           p /= 2.0
#           p2 += 1
#   return p / (m * n), p2

# m, e = maze_count(100, 500)
# # now convert from powers of 2 to powers of 10
# man, exp = frexp(m)
# man, exp = 2 * man, (exp + e - 1) * log10(2)
# man *= 10 ** fmod(exp, 1)
# print(str(round(man, 4)) + 'e' + str(int(exp)))

from math import pi,sin,log,exp

def nst(n,m):
    logs = 0
    sq1 = [sin(i*pi/(2*n))**2 for i in range(n)]
    sq2 = [sin(i*pi/(2*m))**2 for i in range(m)]
    for s1 in sq1:
        for s2 in sq2:
            if s1+s2>0:
                logs += log(4*(s1+s2))
    log10 = (logs-log(n*m))/log(10)
    e = int(log10)
    m = 10**(log10-e)
    return "%.4fe%s"%(m,e)

print (nst(100,500))