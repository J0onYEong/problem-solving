import sys
sys.setrecursionlimit(10**6)

N = int(sys.stdin.readline())

dp = [[-1 for _ in range(10+1)] for _ in range(100+1)]

mod = 1000000000

def recursive(pos, number):
    if pos == N:
        return 1;

    global dp
    if dp[pos][number] != -1:
        return dp[pos][number]
    
    dp[pos][number] = 0

    if number+1 <= 9:
        dp[pos][number] += recursive(pos+1, number+1) % mod
    if number-1 >= 0:
        dp[pos][number] += recursive(pos+1, number-1) % mod

    return dp[pos][number];

result = 0

for start in range(1, 10):
    result += recursive(1, start)
    result %= mod

print(result)