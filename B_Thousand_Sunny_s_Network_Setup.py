
n, k = map(int, input().split())
speeds = list(map(int, input().split()))
speeds.sort(reverse=True)
print(speeds[k-1])