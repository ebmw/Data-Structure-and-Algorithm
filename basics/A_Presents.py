def presents(n, p):
    # Initialize the result array
    result = [0] * n
    
    # Loop through the list p and reverse the mapping
    for i in range(n):
        result[p[i] - 1] = i + 1
    
    return result

n = int(input())
p = list(map(int, input().split()))

result = presents(n, p)

print(" ".join(map(str, result)))
