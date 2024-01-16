has_multi = True

M = 1000000007
R = 500
C = 500

grid = [[1 if (j == 0 or i == 0) else 0 for j in range(C+1)]for i in range(R+1)]


for i in range(1, R+1):
    for j in range(1, C+1):
        grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % M

for _ in range(int(input()) if has_multi else 1):
    m , n = list(map(int, input().split()))  

    print(grid[m][n])