t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    
    operations = 0
    
    while y > 0:
        best_addition = 1  # Start with adding 1
        p = 0
        
        while x * (10**p) <= y:
            best_addition = x * (10**p)
            p += 1
        
        count = y // best_addition
        operations += count
        y -= count * best_addition
    
    print(operations)