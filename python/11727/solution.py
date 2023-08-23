import sys

ipt = sys.stdin.readline

n = int(ipt())

dp = [0, 1, 3]

mod = 10007

# 3 ~ n
for i in range(3, n+1):
    dp.append(dp[i-1] + 2 * dp[i-2]) 

print(dp[n] % mod) 