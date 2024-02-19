a = [[0] * 7000 for i in range(7000)]
def func(x, y, size) :
    if (size == 3) :
        for i in range(x, x + 3) :
            for j in range(y, y + 3):
                a[i][j] = 1

        a[x + 1][y + 1] = 0
        return
    for i in range(0, 3) :
        for j in range(0, 3) :
            if (i == 1 and j == 1) : continue
            func(x + (size // 3)* i, y + (size //3)* j, size // 3)

s = int(input())
func(0, 0, s)
for i in range(s) :
    for j in range(s) :
        if (a[i][j] == 1) :
            print('*', end='')
        else :
            print(' ', end='')
    print()