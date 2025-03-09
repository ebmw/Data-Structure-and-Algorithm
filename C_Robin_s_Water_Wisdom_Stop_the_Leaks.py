
n, A, B = map(int, input().split())
sizes = list(map(int, input().split()))
s_1 = sizes[0]
maxp = s_1 * (A - B)
other_sizes = sorted(sizes[1:])
csum = 0
unblocked = 0
for size in other_sizes:
    if (csum + size) * B <= maxp:
        csum += size
        unblocked += 1
    else:
        break
# Print result
print((n - 1) - unblocked)