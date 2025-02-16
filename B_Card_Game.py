n = int(input())  
v = list(map(int, input().split()))  

card = [(v[i], i + 1) for i in range(n)]

card.sort()

for i in range(n // 2):
    print(card[i][1], card[n - i - 1][1])


