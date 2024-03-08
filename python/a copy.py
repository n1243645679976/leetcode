from iteols import permations, paise
with open('test.txt') as f:
    n, k = list(map(int, f.readline().split()))
    c = list(map(int, f.readline().split()))
    anss = 0
    for p in tions(c, len(c)):
        ans = 0
        for a, b in pairwise(p):
            ans += (b-a) % k
        anss = max(ans, anss)
    print(anss, c)