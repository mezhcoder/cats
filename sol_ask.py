data = []
n = int(input())
data = list(map(int, input().split()))

value = int(input())
 
mid = len(data) // 2
low = 0
high = len(data) - 1
 
while data[mid] != value and low <= high:
    if value > data[mid]:
        low = mid + 1
    else:
        high = mid - 1
    mid = (low + high) // 2
 
if low <= high:
    print("YES")
else:
    print("NO")