import sys
from bisect import bisect

ipt = sys.stdin.readline

N, M = map(int,ipt().split())

data = []

def binary_search(list, target, start, end):
    middle_index = int((start+end)/2)
    middle_element = list[middle_index]
    
    if start != end:
        if target <= middle_element:
            return binary_search(list, target, start, middle_index)
        else:
            return binary_search(list, target, middle_index+1, end)
    return middle_index

for _ in range(N):
    key, value = ipt().split() 
    key = str(key)
    value = int(value)
    data.append((key, value))

c_list = []

for _ in range(M):
    c_list.append(int(ipt()))

value_list = list(map(lambda element : element[1], data))

result = []

for c in c_list:
    index = binary_search(value_list, c, 0, len(value_list)-1)
    print(data[index][0])
    
    