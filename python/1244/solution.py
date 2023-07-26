N = int(input())

switch_state = list(map(int, input().split()))

M = int(input())

t = [list(map(int, input().split())) for _ in range(M)]

def flip_multiple(tar):
    # range 지정땜에 많이 틀림
    for i in range(1, N+1):
        temp = tar * i
        if temp > N:
            return
        
        switch_state[temp-1] = 0 if switch_state[temp-1] == 1 else 1
    return

def flip_symmetry(center):
    switch_state[center-1] = 0 if switch_state[center-1] == 1 else 1
    for i in range(1, N+1):
        left = center-i
        right = center+i
        if left >= 1 and right <= N:   
            if switch_state[left-1] == switch_state[right-1]:
                switch_state[left-1] = switch_state[right-1] = 0 if switch_state[right-1] == 1 else 1
            else:
                return
        else:
            return

for e in t:
    if e[0] == 1:
        flip_multiple(e[1])
    else:
        flip_symmetry(e[1])

for i in range(1, N+1):
    print(switch_state[i-1], end = " ")
    if i % 20 == 0 :
        print()

