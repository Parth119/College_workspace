dob={"Meet":"30/01/2002", "Parth":"18/06/2002", "Yash":"02/07/2001", "Vedant":"17/07/2001", "Keertan":"11/09/2001", "Ruchit":"13/11/2001", "Mustafa":"28/11/2000", "Rakesh":"23/12/2000"}
name= input("Enter name:")
l1= name.split()

for i in l1:
    if i in dob.keys():
        person=i
        print(" ".join([person," DOB is :",dob[person]]))
    else:
        print(str(i)+" Data Entry Not found!")