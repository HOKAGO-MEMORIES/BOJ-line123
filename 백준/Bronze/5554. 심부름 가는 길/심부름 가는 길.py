sum = 0;
for i in range(4):
    sum += int(input())
hour = int(sum / 60)
min = sum % 60
print(hour, min, sep = '\n')
