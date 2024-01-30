import sys

ipt = sys.stdin.readline

N = int(ipt())

target = [int(ipt()) for _ in range(N)]

temp = [0 for _ in range(N)]

def merge(start, end):
    global target, temp
    middle = int((start+end)/2)

    temp_index = start;
    i1 = start
    i2 = middle+1
    while temp_index <= end:
        if i1 > middle:
            temp[temp_index] = target[i2]
            temp_index+=1
            i2+=1
            continue
        if i2 > end:
            temp[temp_index] = target[i1]
            temp_index+=1
            i1+=1
            continue

        t1 = target[i1]
        t2 = target[i2] 
        if t1 <= t2:
            temp[temp_index] = t1
            i1+=1
        else:
            temp[temp_index] = t2
            i2+=1
        temp_index+=1

    for i in range(start, end+1):
        target[i] = temp[i]


def merge_sort(start, end):
    global target
    if start == end:
        return;
    middle_i = int((start+end)/2)
    merge_sort(start, middle_i)
    merge_sort(middle_i+1, end)
    merge(start, end)

merge_sort(0, N-1)

for element in target:
    print(element)