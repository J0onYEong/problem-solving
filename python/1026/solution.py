N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)

result=0

for index in range(N):
    result += A[index] * B[index]

print(result)