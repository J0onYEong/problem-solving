import sys
from bisect import bisect_left, bisect_right

ipt = sys.stdin.readline

N = int(ipt())

card_list = list(map(int, ipt().split()))

M = int(ipt())

check_list = list(map(int, ipt().split()))

card_list.sort()

result = []

for check in check_list:
    left = bisect_left(card_list, check)
    right = bisect_right(card_list, check)
    result.append(right-left)
print(*result)