from bisect import bisect

N = int(input())

card1 = list(map(int, input().split()))

M = int(input())

card2 = list(map(int, input().split()))

card1.sort()

for card in card2:
    # 1부터 시작하는 인덱스를 반환함
    index = bisect(card1, card)-1
    print(1 if card1[index] == card else 0, end=" ")