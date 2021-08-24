n=int(input("Enter number of terms :"))
num1, num2= 0, 1
count =0
while count < n:
    print(num1)
    temp = num1+num2
    num1 = num2
    num2 = temp

    count+=1