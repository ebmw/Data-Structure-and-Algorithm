n = int(input())
matrix= [list(map(int , input().split())) for _ in range(n)]
res= 0
for row in matrix :
    if (row.count(1) > 1):
        res += 1
print(res)