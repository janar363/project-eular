from math import ceil

has_multi = True

fact = {0: 1}

for i in range(1, 14):
    fact[i] = fact[i-1] * i

for _ in range(int(input()) if has_multi else 1):
    n = int(input())
    permutation = ""
    first = "abcdefghijklm"
    available = [ch for ch in first]
    for i in range(len(first), 0, -1):
        next_char = available[ceil(n / fact[i-1])-1]
        permutation += next_char
        available.remove(next_char)

        n = n % fact[i-1]

    print(permutation)
