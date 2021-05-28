data = []
n = int(input())
data = list(map(int, input().split()))

value = int(input())

answer = "NO"
for i in range(0, n):
    if (value == data[i]):
        answer = "YES"
        break
print(answer)