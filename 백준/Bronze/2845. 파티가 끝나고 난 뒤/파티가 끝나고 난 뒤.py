l, p = map(int, input().split())
ans = l * p
news = list(map(int, input().split()))
for i in news:
    print(i - ans, end = " ")
