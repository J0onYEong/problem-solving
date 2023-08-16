import sys

ipt = sys.stdin.readline

N = int(ipt())

request = list(map(int, ipt().split()))

M = int(ipt())

def calculate_sum(maximum):
    sum = 0
    for req in request:
        sum += req if req < maximum else maximum
    return sum

def binary_search(start, end):
    if start == end:
        return start

    middle = int((start + end)/2)+1

    sum = calculate_sum(middle)
    
    if M > sum:
        return binary_search(middle, end)
    if M < sum:
        return binary_search(start, middle-1)
    return middle

print(binary_search(0, max(request)))