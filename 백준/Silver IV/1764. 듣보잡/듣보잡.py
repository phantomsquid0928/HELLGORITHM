n, m = map(int, input().split())

## dict == map
a = []
b = []
for i in range(n):
    a.append(input())
for i in range(m):
    b.append(input())

res = list(set(a).intersection(b))

res.sort()
print(len(res))

for i in res:
    print(i)