k, n = map(int, input().split())
arr = []
max_length = 0

for i in range(k):
    tmp = int(input())
    arr.append(tmp)
    if tmp > max_length:
        max_length = tmp
    

left = 1
right = max_length

while (left <= right):
    mid = (left + right) // 2
    cnt = 0
    for i in range(k):
        cnt += arr[i] // mid
    if cnt >= n:
        left = mid + 1
    else:
        right = mid - 1

print(left)
