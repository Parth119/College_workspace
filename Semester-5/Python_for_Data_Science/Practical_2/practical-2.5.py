def even(li):
    if li%2==0:
        print(li,end=" ")

li= [int(n) for n in input("Enter element :").split()]
print("\nEven numbers are:")
for i in li:
    rslt=even(i)