n = int(input())
origin = list(map(int, input().split()))

sort = sorted(list(set(origin)))
dic = {sort[i]:i for i in ragne(len(sort))}

for i in arr:
    print(dic[i], end=' ')
