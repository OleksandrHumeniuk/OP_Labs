def A (n,m):
    
    if (n == 0):
        return m+1;
    
    elif (m == 0):
        return A(n-1,1)
    
    else:
        return A(n-1,(A(n,m-1)))



n = int(input("Input number n: "))
m = int(input("Input number m: "))

print("The result is",(A(n,m)))
    


    
  
