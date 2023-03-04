import random
T = 10
print(T)
for i in range(T):
    a, b = random.choice(range(10000)), random.choice(range(10000))
    print(a, b)
    print(''.join(random.choices('ABCDEFG', k=a)))
    print(''.join(random.choices('ABCDEFG', k=a)))
