def prod(num, i, k):
    p = 1
    for ch in num[i:i+k]:
        p *= int(ch)

    return p


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    num = input()

    mx = prod(num, 0, k)
    prev = mx
    for i in range(1, len(num)-k):
        next = prod(num, i, k)

        if next > mx:
            mx = next
    
    print(mx)