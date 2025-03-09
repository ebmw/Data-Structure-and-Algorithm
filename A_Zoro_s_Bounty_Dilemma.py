t = int(input())  # Number of test cases

for _ in range(t):
    s = input().strip()
    if '<' in s and '>' in s:
        print("?")
    elif '<' in s:
        print("<")
    elif '>' in s:
        print(">")
    else:
        print("=")
        
