import random
T = 100
n = random.randint(1, 10)
print(T)
for i in range(T):
    print(n)
    for i in range(n):
        print(random.randint(1, 10000000), end=' ')
    print()

    