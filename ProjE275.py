nmax = 18

busy = [(0, 0)] + nmax * [None]
front = [(0, 1)]
board = [[0 for j in range(nmax + 2)] for i in range(2 * nmax + 1)]
board[nmax][0] = 1
board[nmax][1] = 2

nf = 1
c = 0
cs = 0
w = 0

def step(n, m):
    global nf, busy, front, board, c, cs, w
    p = front[m]
    x, y = p
    busy[n] = p
    board[x+nmax][y] = 1
    w += x
    if n == nmax:
        if w == 0:
            c += 1
            if all(board[nmax-xx][yy] == 1 for xx, yy in busy):
                cs += 1
    else:
        nff = nf
        for xx, yy in [(x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)]:
            if yy > 0 and board[xx+nmax][yy] == 0:
                board[xx+nmax][yy] = 2
                if nf < len(front):
                    front[nf] = (xx, yy)
                else:
                    front.append((xx, yy))
                nf += 1
        for mm in range(m + 1, nf):
            step(n + 1, mm)
        for i in range(nff, nf):
            xx, yy = front[i]
            board[xx+nmax][yy] = 0
        nf = nff
    board[x+nmax][y] = 2
    w -= x

step(1, 0)
print((c + cs) // 2)