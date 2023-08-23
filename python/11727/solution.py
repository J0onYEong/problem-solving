import sys

ipt = sys.stdin.readline

n = int(ipt())

dp=[-1 for _ in range(n+1)] 

mod = 10007

def recursive(pos):
    global n

    if pos == n+1:
        return 1;

    if dp[pos] != -1:
        return dp[pos];

    dp[pos] = 0
        
    dp[pos] += recursive(pos+1) % mod
    if pos+2 <= n+1:
        dp[pos] += 2*(recursive(pos+2) % mod)
    return dp[pos] % mod

print(recursive(1))