
p, m = map(int, input().split())

players = [list(input().split()) for _ in range(p)]

players=list(map(lambda x : [int(x[0]), x[1]], players))

startStr = 'Started!'

waitStr = 'Waiting!'

rooms = []

for player in players:
    check = False
    for room in rooms:
        if len(room) >= m:
            continue
        fp_level = room[0][0]
        if fp_level-10 <= player[0] and player[0] <= fp_level+10:
            check = True
            room.append(player)
            break
    if check == False:
        new_room = [player]
        rooms.append(new_room)

for room in rooms: 
    if len(room) >= m:
        print(startStr)
    else :
        print(waitStr)
    
    room.sort(key= lambda x : x[1])
    for p in room:
        print(p[0], p[1])
        
        