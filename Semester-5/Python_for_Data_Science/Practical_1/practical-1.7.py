def prime(n):
    flag=0
    for i in range(2,n):
        if(n%i==0):
            flag=1
    if(flag==0):
        print(n)


a = int(input("Enter the number:"))
for j in range(2,a):
    prime(j)