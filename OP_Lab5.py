limit = 1000

for i in range(1, limit+1):

    curNum = i
    opNum = 0

    digits = 0

    while (curNum != 0):

        digits = digits + 1
        curNum = curNum // 10

    curNum = i
    
    for j in range(digits-1,-1,-1):

        opNum = opNum + (curNum%10)*(10**j)
        curNum = curNum // 10

    if (i == opNum):
        print (opNum)
