code = list(map(int, input().split()))
ans = 0
for i in code:
  ans += i * i
print(ans % 10)