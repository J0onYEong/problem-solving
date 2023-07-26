
N, K = map(int, input().split())

score = [list(map(int, input().split())) for _ in range(N)]

score.sort(key=lambda e : (e[1], e[2], e[3]), reverse=True)

index = [score[i][0] for i in range(N)].index(K)

for i in range(N):
    if score[index][1:] == score[i][1:]:
        print(i+1)
        break

        
    

