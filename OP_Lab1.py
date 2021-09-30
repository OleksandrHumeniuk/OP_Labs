print ("Please enter the value of b :") 
b = int (input())

print ("Please enter the value of q :") 
q = int (input())

print ("Please enter the value of n :")
n = int (input())

sum = b 

for x in range (1,n):
    b *= q
    sum += b

print ("The sum is " + str(sum))
    

    



