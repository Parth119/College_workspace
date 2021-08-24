n = int(input("Enter number :"))
temp = n
sum = 0
while n > 0:
    a = n % 10
    sum = sum+(a*a*a)
    n= n//10
if (sum==temp):
    print(str(temp)+" is armstrong number.")
else:
    print(str(temp)+" is not armstrong number.")