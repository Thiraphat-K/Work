limit = 1000
t1 = [[True for i in range(limit+1)] for j in range(limit+1)]
t2 = [[True for i in range(limit+1)] for j in range(limit+1)]
t3 = [[True for i in range(limit+1)] for j in range(limit+1)]

def mark(a,b,c):
    t1[a][b] = False
    t1[a][c] = False
    t1[b][c] = False
    t2[a][c-b] = False
    t2[b][c-a] = False
    t2[c][b-a] = False
    t3[b-a][c-b] = False

def isLosing(a,b,c):
    return t1[a][b] and t1[a][c] and t1[b][c] and t2[a][c-b] and t2[b][c-a] and t2[c][b-a] and t3[b-a][c-b]

mark(0,0,0)
answer = 0
for c in range(limit+1):
    for b in range(c+1):
        for a in range(b+1):
            if isLosing(a,b,c):
                answer += a + b + c
                mark(a,b,c)

print(answer)