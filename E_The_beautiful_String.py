t = int(input().strip())

for _ in range(t):
    s = list(input().strip()) 
    q = int(input().strip())

    n = len(s)
    active_positions = set()
    for i in range(n - 3):
        if s[i:i+4] == ["1", "1", "0", "0"]:
            active_positions.add(i)

    results = []
    for _ in range(q):
        i, v = map(int, input().split())
        i -= 1  

        if s[i] != str(v):  
       
            for j in range(max(0, i - 3), min(n - 3, i + 1)):
                if s[j:j+4] == ["1", "1", "0", "0"]:
                    active_positions.discard(j)

            # Apply modification
            s[i] = str(v)

            for j in range(max(0, i - 3), min(n - 3, i + 1)):
                if s[j:j+4] == ["1", "1", "0", "0"]:
                    active_positions.add(j)

        results.append("YES" if active_positions else "NO")

    print("\n".join(results))
