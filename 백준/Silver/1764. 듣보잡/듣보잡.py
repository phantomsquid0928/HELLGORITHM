
n, k = map(int, input().split())

dict = {}
res = []
for i in range(n):
    t = str(input())
    dict[t] = 1
for i in range(k):
    t = str(input())
    if t in dict.keys():
        res.append(t)

print(len(res))
res.sort()
for i in res:
    print(i)