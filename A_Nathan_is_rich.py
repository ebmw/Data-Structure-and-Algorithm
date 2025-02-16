import sys
import math

t = int(sys.stdin.readline().strip())
for _ in range(t):
    n = int(sys.stdin.readline().strip())
    print(math.ceil(n / 4))
