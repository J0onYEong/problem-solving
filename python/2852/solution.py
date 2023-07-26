
N = int(input())

score = [list(input().split()) for _ in range(N)]

def time_gap(t1, t2):
    h1, m1 = map(int, t1.split(":"))
    h2, m2 = map(int, t2.split(":"))
    
    rh = 0
    rm = 0

    if m1 > m2:
        rm = m2 - m1 + 60
        rh = h2 - h1 - 1
    else:
        rm = m2 - m1
        rh = h2 - h1
    return '{:02d}:{:02d}'.format(rh, rm)
    
def time_plus(t1, t2):
    h1, m1 = map(int, t1.split(":"))
    h2, m2 = map(int, t2.split(":"))
    
    rh = h1+h2
    rm = m1+m2

    if(rm >= 60):
        rh += 1
        rm -= 60
    
    return '{:02d}:{:02d}'.format(rh, rm)


s1 = 0
s2 = 0

t1_time = '00:00'
t2_time = '00:00'

t1_winning = False
t2_winning = False

last_time = '00:00'

for i, s in enumerate(score):
    if s[0] == '1':
        s1+=1
    else:
        s2+=1
    
    if s1 > s2:
        if t1_winning:
            continue;
        elif t2_winning:
            t2_winning = False
            tg = time_gap(last_time, s[1])
            t2_time = time_plus(t2_time, tg)
        t1_winning = True
        last_time = s[1]
    elif s1 < s2:
        if t2_winning:
            continue
        elif t1_winning:
            t1_winning = False
            tg = time_gap(last_time, s[1])
            t1_time = time_plus(t1_time, tg)
        t2_winning = True
        last_time = s[1]
    
    if s1 == s2:
        if t1_winning:
            t1_winning = False
            tg = time_gap(last_time, s[1])
            t1_time = time_plus(t1_time, tg)
        elif t2_winning:
            t2_winning = False
            tg = time_gap(last_time, s[1])
            t2_time = time_plus(t2_time, tg)
    
if t1_winning:
    t1_winning = False
    tg = time_gap(last_time, '48:00')
    t1_time = time_plus(t1_time, tg)
elif t2_winning:
    t2_winning = False
    tg = time_gap(last_time, '48:00')
    t2_time = time_plus(t2_time, tg)
        

print(t1_time)
print(t2_time)


