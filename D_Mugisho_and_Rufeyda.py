n, t = map(int, input().split())

lower_bound = 10 ** (n - 1)
upper_bound = (10 ** n) - 1

if lower_bound > upper_bound:
    print(-1)
else:
    remainder = lower_bound % t
    if remainder == 0:
        print(lower_bound)
    else:
        smallest_number = lower_bound + (t - remainder)
        if smallest_number <= upper_bound:
            print(smallest_number)
        else:
            print(-1)