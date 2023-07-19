

inputStr = input()
inputStr+=' '

p1 = 'AAAA'
p2 = 'BB'
resultStr = ""

check = False
xCount = 0
for i in range(len(inputStr)):
    if inputStr[i] == 'X':
        if check:
            xCount+=1
            if xCount % 4 == 0:
                resultStr+=p1
                xCount=0
                check = False
        else:
            xCount=1
            check=True
    else:
        if check:
            if xCount % 2 == 0:
                resultStr+=p2
                check=False
                xCount=0
            else:
                print(-1)
                exit()
        if inputStr[i] == '.':
            resultStr+='.'

print(resultStr)
        
        
