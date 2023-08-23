import sys
sys.setrecursionlimit(10**6)
ipt = sys.stdin.readline

X = int(ipt())

dp = [0, 0, 1, 1]

for i in range(4, X+1):
    temp = dp[i-1] + 1
    if i % 3 == 0:
        temp = min(temp, dp[i//3]+1)
    if i % 2 == 0:
        temp = min(temp, dp[i//2]+1)
    dp.append(temp)

calc_cnt = dp[X]
print(calc_cnt)
temp = X
result = [X]
while(temp != 1):
    if dp[temp] == dp[temp-1] + 1:
        temp -= 1
    elif temp % 2==0 and dp[temp] == dp[temp//2]+1:
        temp //= 2
    elif temp % 3==0 and dp[temp] == dp[temp//3]+1:
        temp //= 3
    result.append(temp)

print(*result)