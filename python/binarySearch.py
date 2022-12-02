def bs_c_leftmost(x, lo=0, hi=None, *, key=None):
    while lo < hi:
        mid = (lo + hi) // 2
        if x <= key(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def bs_c_rightmost(x, lo=0, hi=None, *, key=None):
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if key(mid) <= x:
            lo = mid
        else:
            hi = mid - 1
    return lo
    
def bs_nc_leftmost(x, lo=0, hi=None, *, key=None):
    while lo < hi:
        mid = (lo + hi) // 2
        if x < key(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def bs_nc_rightmost(x, lo=0, hi=None, *, key=None):
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if key(mid) < x:
            lo = mid
        else:
            hi = mid - 1
    return lo