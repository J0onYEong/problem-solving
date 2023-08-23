import sys
sys.setrecursionlimit(10**6)
ipt = sys.stdin.readline

X = int(ipt())

dp = [-1 for _ in range(1000000+1)]
dp[1] = 0
def recursive(number):
    global dp
    if number == 1:
        return 0
    if dp[number] != -1:
        return dp[number]
    result = 1000000
    if number % 3 == 0:
        result = min(result, recursive(number//3))
    if number % 2 == 0:
        result = min(result, recursive(number//2))
    result = min(result, recursive(number-1))

    dp[number]=result+1
    return dp[number]

calc_cnt = recursive(X)
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