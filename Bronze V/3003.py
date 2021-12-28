black = [1, 1, 2, 2, 2, 8]
white = list(map(int, input().split()))
for i in range(6):
    print(black[i] - white[i], end = " ")
