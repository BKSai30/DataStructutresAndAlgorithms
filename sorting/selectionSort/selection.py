def selection(l):
    for i in range(0,len(l)):
        min=i
        for j in range(i,len(l)):
            if(l[j]<l[min]):
                min=j
        l[min],l[i]=l[i],l[min]
    return l
l=[5,3,1,2,4]
l=selection(l)
print(l)
