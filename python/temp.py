def getint():
    return int(input())
def getfloat():
    return float(input())
def getints():
    return list(map(int, input().split()))
def getfloats():
    return list(map(float, input().split()))


T = getint()
for i in range(T):
    n = getint()
    s = input()
    quest = []
    for c in s:
        if c == 'Q':
            quest.append('Q')
        if c == 'A':
            if quest:
                quest.pop()
    print('Yes' if len(quest) == 0 else 'No')