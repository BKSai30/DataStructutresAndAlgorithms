def bubble(l):
    for i in range(0,len(l)):
        for j in range(0,len(l)-1-i):
            if(l[j]>l[j+1]):
                l[j],l[j+1]=l[j+1],l[j]
    return l
l=[10,4,2,-5,25]
print(bubble(l))