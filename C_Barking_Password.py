p = input()
n = int(input())
w = [input()for _ in range(n)]

p1, p2 = p[0], p[1]

if p in w:
    print("YES")
else:
    f, s = False, False
    for word in w:
        if word[1] == p1:
            f = True
        if word[0] == p2:
            s = True
        if f and s:
            print("YES")
            break
    else:
        print("NO")
