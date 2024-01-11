import time

start_time = time.time() 

# Your Python program code
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

    



    


# ...

end_time = time.time()

print("Program run time:", round(end_time - start_time, 5), "seconds")


