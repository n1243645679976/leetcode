from itertools import permutations, pairwise
with open('test.txt') as f:
    n, k = list(map(int, f.readline().split()))
    c = list(map(int, f.readline().split()))
    anss = 0
    for p in permutations(c, len(c)):
        ans = 0
        for a, b in pairwise(p):
            ans += (b-a) % k
        if ans > anss:
            c = p
        anss = max(ans, anss)
    print(anss, c)