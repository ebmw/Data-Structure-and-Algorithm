n = int(input())
strlist = [input() for _ in range(n)]
res=[]
for row in strlist:
    if len(row) >10 :
        res.append(row[0]+str(len(row)-2)+row[-1])
    else: 
        res.append(row)
print("\n".join(res))