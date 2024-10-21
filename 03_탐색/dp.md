# 이진 탐색 (Binary Search)

## 정의
- 정렬된 리스트에서 특정 값을 찾는 알고리즘
- 중간 값을 기준으로 탐색 범위를 절반씩 줄여 나감.

## 특징
- 정렬된 배열에서만 동작함
- 시간 복잡도는 **O(log n)**으로 매우 효율적
- 반복문 또는 재귀 방식으로 구현 가능
- 탐색 범위를 절반씩 줄이므로 데이터 크기가 클수록 성능이 뛰어남

## 구현
```Python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1  # target이 배열에 없는 경우
```

# 동적 계획법 (DP, Dynamic Programming)

## 정의
- 복잡한 문제를 작은 부분 문제로 나누어 해결하고
- 부분 문제의 결과를 저장하는 분할 정복 방식

## 특징
- 문제를 하위 문제로 분할하여 풀 수 있는 분할 정복 방식의 일종
- 메모이제이션 또는 테이블화를 통해 중복 계산을 방지함
- 최적 부분 구조 (Optimal Substructure)와 중복 부분 문제를 만족하는 문제에 적용 가능
- 시간 복잡도는 일반적으로 O(n) 또는 O(n^2) 수준으로 효율적
- 점화식 중요

## 구현 (피보나치 수열)
```Python
def fibonacci(n):
    dp = [0] * (n + 1)
    dp[1] = 1
    
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp[n]
```