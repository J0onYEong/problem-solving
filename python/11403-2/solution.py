N = int(input())

matrix = [[], *[[0, *map(int , input().split())] for _ in range(N)]]

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if matrix[i][k] and matrix[k][j]:
                matrix[i][j] = 1

for i in range(1, N+1):
    print(*matrix[i][1:])