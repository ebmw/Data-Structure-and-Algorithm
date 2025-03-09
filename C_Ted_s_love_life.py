t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    m = int(input())
    
    for _ in range(m):
        s = input().strip()
        if len(s) != n:
            print("NO")
            continue
            
        nc = {}
        cn = {}
        is_valid = True
        
        for i in range(n):
            num, char = l[i], s[i]
            
            if num in nc:
                if nc[num] != char:
                    is_valid = False
                    break
            else:
                nc[num] = char
            
            if char in cn:
                if cn[char] != num:
                    is_valid = False
                    break
            else:
                cn[char] = num
        
        print("YES" if is_valid else "NO")