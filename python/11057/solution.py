import sys
sys.setrecursionlimit(10**6)

ipt = sys.stdin.readline

N = int(ipt())

dp = [[-1 for _ in range(10+1)] for _ in range(N+1)]

def recursive(pos, number):
    global dp
    if pos == N:
        dp[pos][number] = 1
        return 1

    if dp[pos][number] != -1:
        return dp[pos][number]
    
    dp[pos][number] = 0
    for i in range(0, 10):
        if number+i > 9:
            break;
        dp[pos][number] += recursive(pos+1, number+i)
    return dp[pos][number]

result = 0
for number in range(0, 10):
    result += recursive(1, number) % 10007
print(result % 10007)