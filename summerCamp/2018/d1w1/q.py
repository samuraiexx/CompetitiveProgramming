s = raw_input()
v = {} 
alphabet = "abcdefghijklmnopqrstuvwxyz"

for c in s:
    if c in v:
        v[c] += 1
    else:
        v[c] = 1
        
f = [1]

for i in range(1,33):
    f.append(i*f[i-1]);

ans = 0
n = len(s)
for i in range(n):
    c = s[i]
    sum = 0
    for j in alphabet:
        if j in s:
            if j == c:
                break
            prod = 1
            for k in alphabet:
                if k in s: 
                    prod *= f[v[k]]
            ans += v[j] * f[n-i-1] / prod
    v[c] -= 1

print ans+1
