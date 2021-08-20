import time
def fact(n):
    fact=1
    if n < 0:
        return 0
    elif n==1 or n==0:
        return 1
    else:
        for i in range(n,1,-1):
            fact=fact*i
        return fact
n= int(input("Enter the number :"))
start = time.perf_counter()
print("Factorial is : ",fact(n))
end = time.perf_counter()

print("Time efficiency :",end-start)