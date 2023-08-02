# spanning tree

n = int(input())

p1, p2 = map(int, input().split())

m = int(input())

edge = {}

for i in range(m):
    x, y = map(int, input().split())
    if x in edge:
        edge[x].append(y)
    else:
        edge[x] = [y]
    
    if y in edge:
        edge[y].append(x)
    else:
        edge[y] = [x]

result = -1

def dfs(node, last, value):
    global result
    if p2 == node:
        result = value
        return

    for next in edge[node]:
        if next != last:
            dfs(next, node, value+1)

dfs(p1, -1, 0)

print(result)