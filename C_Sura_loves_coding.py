n= int(input())
enc = input()
res= []
for i , ch in enumerate(enc):
    if i%2 ==0:
        res.append(ch)
    else:
        res.insert(0,ch)
if n %2 == 0:
    res.reverse()
print ("".join(res))
        