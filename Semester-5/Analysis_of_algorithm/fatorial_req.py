import time
def fact(n):
    if n == 1:
        return 1
    else:
        return n*fact(n-1)
n=int(input("Enter number :"))
if n < 0:
    print("The number can't be negative!")
elif n == 0:
    print("The fatorial of 0 is 1")
else:
    start = time.perf_counter()
    print("Factorial of ",n," is :",fact(n))
    end = time.perf_counter()
    print("Time efficiency of given program is :",end-start)