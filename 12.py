import math

has_multi = True

primes = [2]
dp = {0: 1}
def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0: return False

    return True

def add_prime():
    p = primes[-1] + (1 if primes[-1] == 2 else 2)

    while not is_prime(p):
        p += 2

    primes.append(p)

def get_prime_factors(tri):
    p = 0
    prime_factors = {}
    while tri != 1:
        while tri % primes[p] == 0:
            tri //= primes[p]
            if primes[p] in prime_factors:
                prime_factors[primes[p]] += 1
            else:
                prime_factors[primes[p]] = 1

        p += 1
        if p == len(primes): 
            add_prime()

    return prime_factors


def cal_tris():
    mx = 1
    factors = -1
    for i in range(1, 1001):
        if i < factors:
            dp[i] = mx
            continue
        while factors <= i:
            mx += 1
            tri = mx * (mx + 1) // 2

            pf = get_prime_factors(tri)

            factors = 1
            for _, v in pf.items():
                factors *= (v+1)

        dp[i] = mx

cal_tris()

for _ in range(int(input()) if has_multi else 1):
    n = int(input())
    print(dp[n] * (dp[n]+1) // 2)