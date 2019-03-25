n = input()
fib = [0, 1, 1]
ans = 0
for i in range(3, n+1):
    fib.append(fib[i-1] + fib[i-3])
    ans = fib[i-1] + fib[i-3]
if n < 3:
    print fib[n]
else:
    print ans
