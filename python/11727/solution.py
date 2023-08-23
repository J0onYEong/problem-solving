import sys

ipt = sys.stdin.readline

n = int(ipt())

dp=[0 for _ in range(n+1)]
dp[0] = 0
dp[1] = 1
dp[2] = 3

mod = 10007

# 3 ~ n
for i in range(3, n+1):
    dp[i] = dp[i-1] + 2 * dp[i-2]

print(dp[n] % mod) 