x = input()

ok = 1
c = -1
cnt = -1
cnt2 = 0
s = raw_input()
v = map(int, s.split())
for y in v:
  if c == -1:
    c = y 
    cnt2 += 1
  elif c == y:
    cnt2 += 1
  elif cnt == -1:
    c = y
    cnt = cnt2
    cnt2 = 1
  elif cnt2 != cnt:
    ok = 0
  else:
    c = y
    cnt2 = 1

if ok == 0 or cnt2 != cnt and cnt != -1:
  print 'NO'
else:
  print 'YES'
