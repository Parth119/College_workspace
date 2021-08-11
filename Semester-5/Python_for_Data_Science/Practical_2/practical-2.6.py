def count_char(str):
    dict={}
    for n in str:
        keys=dict.keys()
        if n in keys:
            dict[n]+=1
        else:
            dict[n]=1
    return dict

print(count_char('www.covin.gov.in'))