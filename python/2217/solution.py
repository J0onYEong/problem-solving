
N = input()
ropes = []

for _ in range(int(N)):
    rp = input()
    ropes.append(int(rp))

ropes.sort()

result = 0
for index, element in enumerate(reversed(ropes)):
    result = max(result, element * (index+1))

print(result)