
def fourdir(grid):
    add = lambda x, y: x * y + y # 遇0重置為0, 遇1加1
    up = list(zip(*[list(accumulate(c, func=add)) for c in zip(*grid)]))
    down = list(zip(*[list(accumulate(c, func=add)) for c in zip(*grid[::-1])]))[::-1]
    left = [list(accumulate(c, func=add)) for c in grid]
    right = [list(accumulate(c[::-1], func=add))[::-1] for c in grid]
    return up, down, left, right