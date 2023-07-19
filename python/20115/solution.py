result=0

N = input()
drinks = list(map(int, input().split()))

drinks = sorted(drinks)

for i in range(len(drinks)-1):
    result += drinks[i]/2

result += drinks[len(drinks)-1]

print(result)