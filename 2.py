fib = [1, 2]

for _ in range(int(input())):
    n = int(input())

    while fib[-1] + fib[-2] < n:
        fib.append(fib[-1] + fib[-2])

    esum = 0
    for f in fib:
        if f > n:
            break
        if f % 2 == 0:
            esum += f

    print(esum)