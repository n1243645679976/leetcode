def egcd(a, b):
    # ref: https://www.geeksforgeeks.org/python-program-for-basic-and-extended-euclidean-algorithms-2/
    if a == 0 :
        return b,0,1
    gcd,x1,y1 = egcd(b%a, a)
    x = y1 - (b//a) * x1
    y = x1
    return gcd,x,y

def CRT(n1, n2, a1, a2):
    # obtain x (mod lcm(n1, n2))
    #        x = a1 (mod n1)
    #        x = a2 (mod n2)
    #
    # ref: https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Case_of_two_moduli
    
    gcd, m1, m2 = egcd(n1, n2)
    x = a1 * m2 * n2 + a2 * m1 * n1
    x %= n1 * n2 // gcd
    return x

if __name__ == '__main__':
    print(egcd(35, 15))
    print(CRT(35, 6, 12, 7))