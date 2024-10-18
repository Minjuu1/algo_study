def back_tracking(depth):
    for i in range(1, (depth//2) + 1):
        if s[-i:] == s[-2*i:-i]: return -1

    if depth == n:
        for i in range(n): print(s[i], end = '')
        return 0

    for i in range(1, 4):
        s.append(i)
        if back_tracking(depth + 1) == 0:
            return 0
        s.pop()

    n = int(input())
    s = []
    back_tracking(0)