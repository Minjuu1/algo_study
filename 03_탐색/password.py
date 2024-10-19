def dfs(depth, password):
    if len(password) == L:
        count = 0
        for c in password:
            if c in {"a","e","i","o","u"}:
                count += 1

        if count >= 1 and L-count >= 2:
            print(password)
        return
    for i in range(depth, C):
        dfs(i+1, password+alpha[i])


L, C = map(int, input().split())
alpha = sorted(list(input().split()))

dfs(0, "")