import sys
sys.setrecursionlimit(10**6)

ipt = sys.stdin.readline

N, K = map(int, ipt().split())

# nCk = n-1 C k + n-1 C k-1

dp = [ [0 for _ in range(K+1)] for _ in range(N+1) ]

def recursive(n, k):
    global dp
    if n == k or k == 0:
        return 1

    if dp[n][k]:
        return dp[n][k]

    dp[n][k] = (recursive(n-1, k) + recursive(n-1, k-1)) % 10007
    return dp[n][k]

print(recursive(N, K))
