for _ in range(int(input())):
    n = int(input())
    n -= 1
    
    mul_3 = n // 3
    mul_5 = n // 5
    mul_15 = n // 15

    print(3 * mul_3 * (mul_3 + 1) // 2 + 5 * mul_5 * (mul_5 + 1) // 2 - 15 * mul_15 * (mul_15 + 1) // 2)