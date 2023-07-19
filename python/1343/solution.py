

inputStr = input()
p1='AAAA'
p2='BB'
resultStr = ""

inputStr=inputStr.replace('XXXX', 'AAAA')
inputStr=inputStr.replace('XX', 'BB')

if inputStr.find('X') == -1:
    print(inputStr)
else:
    print(-1)

