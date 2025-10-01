def insertion(l):
    if len(l)<=1:
        return l
    else :
        for i in range(1,len(l)):
            j=i-1
            key=l[i]
            while(j>=0 and key<l[j]):
                l[j+1]=l[j]
                j-=1
            l[j+1]=key
    return l
l=[5,3,1,2,4]
print(insertion(l))

