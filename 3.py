import math

def is_prime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0: return False

    return True

for _ in range(int(input())):
    n = int(input())

    if is_prime(n):
        print(n)
        continue
    
    lpf = 0
    for i in range(int(math.sqrt(n)), 1, -1):
        if n % i == 0:
            if n // i > lpf and is_prime(n // i):
                lpf = n // i

            if i > lpf and is_prime(i):
                lpf = i

    print(lpf)