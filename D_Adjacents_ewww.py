def construct_matrix(n):
    if n == 1:
        return [[1]]
    if n == 2:
        return -1
    # Initialize the matrix
    matrix = [[0] * n for _ in range(n)]
    # Fill the matrix in a specific order
    current = 1
    for i in range(n):
        for j in range(n):
            if (i + j) % 2 == 0:
                matrix[i][j] = current
                current += 1
    for i in range(n):
        for j in range(n):
            if (i + j) % 2 != 0:
                matrix[i][j] = current
                current += 1
    return matrix

t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(1)
    elif n == 2:
        print(-1)
    else:
        matrix = construct_matrix(n)
        for row in matrix:
            print(" ".join(map(str, row)))