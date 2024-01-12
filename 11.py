dirs = [(-1, 0), (0, 1), (1, 0), (0, -1), (-1, -1), (-1, 1), (1, 1), (1, -1)]

def invalid(pos):
    if pos[0] < 0 or pos[0] >= len(grid) or pos[1] < 0 or pos[1] >= len(grid[0]): return True

    return False

def get_prod(i, j):
    global grid

    max_prod = -1
    for dir in dirs:
        prod = 1
        for d in range(4):
            npos = (i + dir[0] * d, j + dir[1] * d)

            if invalid(npos): break

            prod *= grid[npos[0]][npos[1]]

        else:
            if prod > max_prod:
                max_prod = prod

    return max_prod

has_multi = False
for _ in range(int(input()) if has_multi else 1):
    grid = [list(map(int, input().strip().split())) for _ in range(20)]
    
    max_prod = -1
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            prod = get_prod(i , j)

            if prod > max_prod:
                max_prod = prod

    print(max_prod)