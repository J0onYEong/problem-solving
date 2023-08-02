N = int(input())

matrix = [[0, *list(map(int , input().split()))] for _ in range(N)]

matrix = [[], *matrix]

direc = [[] for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        if matrix[i][j]:
            direc[i].append(j)


def bfs(start):
    visit = [0 for _ in range(N+1)]
    q = [start]

    while len(q) != 0:
        front = q[0]
        q.pop(0)

        for next in direc[front]:
            if not visit[next]:
                visit[next] = 1
                if next != start:
                    q.append(next)
                 
    
    return visit

for i in range(1, N+1):
    temp = bfs(i)
    for i in range(1, N+1):
        print(temp[i], end = " ")
    print()