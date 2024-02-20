import sys
a = [[0] * 65 for i in range(65)]

def func(x, y, size) :
    chk0 = 0
    chk1 = 1
    for i in range(x, x + size):
        for j in range(y, y + size):
            if (a[i][j] == 1) : chk0 = 1
            if (a[i][j] == 0) : chk1 = 0
    if chk0 == 0:
        return '0'
    if chk1 == 1:
        return '1'
    return f'({func(x, y, size//2)}{func(x, y + size//2, size//2)}{func(x + size//2, y, size//2)}{func(x + size//2, y + size//2, size//2)})' 
n = int(input())
for i in range(n):
    a[i] = list(map(int, sys.stdin.readline().rstrip()))

print(func(0, 0, n))