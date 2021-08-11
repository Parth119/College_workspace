lst=[]
n= int(input("Enter number of element :"))
for i in range(n):
    n1= int(input("Enter %d data:" %(i+1)))
    lst.append(n1)
print(lst)

max = lst[0]

for i in range(n):
    if lst[i] > max:
        max= lst[i]
print("Maximum number is : %d" %(max))
