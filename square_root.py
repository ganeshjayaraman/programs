t,x,y,n=0.0001,1.000,0.000,int(input())
while abs((x-y)) > t :
    y = x
    x = 0.5*(x+(n/x))    
print "x is %s",x
