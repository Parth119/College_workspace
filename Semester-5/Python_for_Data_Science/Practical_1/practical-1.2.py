number = 5
for i in range(number):
    for j in range(i+1):
        print("* ", end="")
    print("\n")    
for i in range(number-1,0,-1):
    for j in range(0, i):
        print("* ", end="")
    print("\n")
