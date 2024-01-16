has_multi = True

dp = {}
dp[1] = 2
for i in range(2, 10000+1):
    dp[i] = dp[i-1] * 2

for _ in range(int(input()) if has_multi else 1):
    n = int(input())

    print(sum([int(ch) for ch in str(dp[n])]))