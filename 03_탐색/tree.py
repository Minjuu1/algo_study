n,m = map(int, input().split())
trees = list(map(int, input().split()))

def bs(trees, target):
    left, right = 0, max(trees)
    while left <= right:
        mid = (left + right) // 2
        total = 0

        for height in trees:
            if height > mid:
                total += height - mid
            if total < target:
                right = mid - 1
            else:
                left = mid + 1
        
    return right

print(bs(trees, m))