
import sys

q = []

t = int(input())
for i in range(t):
    ttt = sys.stdin.readline().rstrip()
    # print('ff' + str(i))
    if 'push' in ttt:
        _, num = ttt.split()
        num2 = int(num)
        q.append(num2)
        continue
    if 'front' in ttt:
        if len(q) == 0:
            print(-1)
            continue
        print(q[0])
        continue
    if 'back' in ttt:
        if len(q) == 0:
            print(-1)
            continue
        print(q[len(q) - 1])
        continue
    if 'pop' in ttt:
        if len(q) == 0:
            print(-1)
            continue
        print(q.pop(0))
        continue
    if 'size' in ttt:
        print(len(q))
        continue
    if 'empty' in ttt:
        print(1 if len(q) == 0 else 0)
        continue
