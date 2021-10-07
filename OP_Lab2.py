import math

x = float(input("Please enter the value of x: "))
y = float(input("Please enter the value of y: "))

r = math.sqrt(y*y + x*x)  

if r <= 1:
    a = math.atan(y/x)

    if (x >= 0 and not(x==0 and y < 0)) : 

        if ((math.pi/4 <= a and math.pi/2 >= a) or (math.pi/-4 <= a and 0 >= a)):
            result = True
        
        else:
            result = False

    else:
        
        if ((math.pi/4 < a and math.pi/2 > a) or (math.pi/-4 < a and 0 > a)):
            result = True
        else:
            result = False
else:
    result = False

if (result):
    print ("Your point is inside the selected sectors")
else:
    print ("Your point is not inside the selected sectors")

