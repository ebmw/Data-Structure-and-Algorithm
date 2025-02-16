def can_survive(n, k, a, x):
    zombies = sorted(zip(a, x), key=lambda z: abs(z[1]))
    bull = 0
    for ai, xi in zombies:
        time = abs(xi)
        bull += ai
        if bull > k * time:
            return False
    return True

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    x = list(map(int, input().split()))
    if can_survive(n, k, a, x):
        print("YES")
    else:
        print("NO")