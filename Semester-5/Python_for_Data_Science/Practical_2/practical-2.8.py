dict1= {1:12, 2:1, 3:6}
sort= {}
sort_key= sorted(dict1, key=dict1.get)

#print(sort_key)

for w in sort_key:
    sort[w]= dict1[w]
print(sort)