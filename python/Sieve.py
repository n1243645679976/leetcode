
p = [i for i in range(n+2)] # +1 -> fail on n == 1

for i in chain([2], range(3, math.ceil(math.sqrt(n+1)), 2)):
    if p[i] == i:
        for j in range(i*i, n+1, i):
            p[j] = i