li=[]
for i in range(1,31):
    li.append(i**2)

result= li[:-25] + li[25:]
print(result)