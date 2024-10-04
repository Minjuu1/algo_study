t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    q = list(map(int, input().split()))
    result = 1
    while q:
        if q[0] < max(q):
            q.append(q.pop(0))

        else:
            if m==0: break

            q.pop(0)
            result += 1

        m = m-1 if m>0 else len(q)-1

    print(result)