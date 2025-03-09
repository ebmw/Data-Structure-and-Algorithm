from collections import Counter
t = int(input())  # Number of test cases

test_cases = []

for _ in range(t):
    n, m = map(int, input().split())  
    matrix = [list(map(int, input().split())) for _ in range(n)]  
    test_cases.append(matrix)  

for matrix in test_cases:
    flat_list = [num for row in matrix for num in row]
    count_dict = Counter(flat_list)
    sorted_counts = sorted(count_dict.items(), key=lambda x: x[1])
    mid_index = len(sorted_counts) // 2
    middle_number, middle_count = sorted_counts[mid_index]
    sum_excluding_middle = sum(num for num in flat_list if num != middle_number)
    print(sum_excluding_middle)




