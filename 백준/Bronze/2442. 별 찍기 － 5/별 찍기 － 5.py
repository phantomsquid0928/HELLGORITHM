n = int(input())
for i in range(n):
    for j in range(n - 1 + i, -1, -1): # 4 ~ -1 : 5,     5 ~ -1 : 6 ..
        if (i < j - i) :
            print(' ', end = '')
        else :
            print('*', end = '')
    print()
