li = [int(item) for item in input("Enter the element :").split()]

def shift(list):
    l1=[]
    for i in list:
        l1.insert(len(l1)-1,i)
    return l1

print(shift(li))