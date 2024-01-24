has_multi = True

for _ in range(int(input()) if has_multi else 1):
    N = int(input())
    n = (N + 1) // 2

    ans = 4 * n * (4 * n * n - 1) // 3 - 6 * n * n + 6 * n - 3
    print(ans % 1000000007)