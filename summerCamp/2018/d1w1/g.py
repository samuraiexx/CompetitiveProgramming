n, k = raw_input().split()
print n, k

fat = [1]
for i in range(1, 101):
    fat.append(i*fat[i-1])

n = int(n)
k = int(k)

v = range(1,n+1)

ans = []
while n > 0:
    i = 0
    while k > fat[n-1]:
        k -= fat[n-1]
        i += 1
    ans.append(v[i])
    v.remove(v[i])
    n -= 1

res = ""
for i in ans:
    res += str(i) + " "
print res
