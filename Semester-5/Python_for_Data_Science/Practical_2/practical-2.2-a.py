n=int(input("Enter the number of element :"))
arr=[]
arr1=[]
for i in range(n):
    e=int(input("Enter %d element :"%(i+1)))
    arr.append(e)
    arr1.append(e)
sum=0

for i in range(n):
    if(arr[i]==13):
        arr[i]=0
        if(i+1 < n):
            arr[i+1]=0
    else:
        sum=sum+arr[i]
print("List of array :",arr1)
print("Sum : ",sum)