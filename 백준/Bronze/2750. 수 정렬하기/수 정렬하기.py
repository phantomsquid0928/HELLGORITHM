n = int(input())
arr = []
for i in range(0, n):
    t = int(input())
    arr.append(t)

arr.sort()
for i in arr:
    print(i)