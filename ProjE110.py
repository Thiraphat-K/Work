import functools, operator

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]

smax = 4000000

def q(nmax, p=[]):
    pr = functools.reduce(operator.mul, (primes[i] ** p[i] for i in range(len(p))), 1)
    if (functools.reduce(operator.mul,
                         (2 * p[i] + 1 for i in range(len(p))), 1) - 1) // 2 > smax:
        return min(nmax, pr)
    for i in range(1, 1000 if len(p) == 0 else p[-1] + 1):
        if pr * primes[len(p)] ** i >= nmax:
            break
        nmax = q(nmax, p + [i])
    return nmax

nmax = 1
s = 1
for p in primes:
    if s > smax:
        break
    s *= 3
    nmax *= p

print(q(nmax))

# import copy
# import operator
# import functools

# primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

# def c(alpha):
#     def r(j):
#         if j == 0:
#             return alpha[0] + 1
#         return (2 * alpha[j] + 1) * r(j - 1) - alpha[j]
#     return r(len(alpha) - 1)


# fs = []
# t = []


# def f(alpha):
#     print(f"call on {alpha}")
#     if alpha[0] > 10:
#         return None
#     k = c(alpha)
#     if k > 4000000:
#         fs.append((alpha, k))
#         return None
#     a = copy.copy(alpha)
#     a[0] += 1
#     if a not in t:
#         t.append(a)
#         f(a)
#     for p in range(1, len(alpha)):
#         if alpha[p] < min(alpha[:p]):
#             a = copy.copy(alpha)
#             a[p] += 1
#             if a not in t:
#                 t.append(a)
#                 f(a)
#     a = copy.copy(alpha)
#     a.append(1)
#     if a not in t:
#         t.append(a)
#         f(a)


# f([1, 1, 1, 1, 1, 1, 1, 1])
# n, k = min(fs, key=lambda a: functools.reduce(operator.mul, [primes[i] ** p for i, p in enumerate(a[0])]))
# print(functools.reduce(operator.mul, [primes[i] ** p for i, p in enumerate(n)]), k)