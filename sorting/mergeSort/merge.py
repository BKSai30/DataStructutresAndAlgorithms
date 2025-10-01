def merge(l1,l2):
    n1,n2,m1,m2=len(l1),len(l2),0,0
    l=[]
    while(m1+m2<n1+n2):
        if(m1==n1):
            l.append(l2[m2])
            m2+=1
        elif(m2==n2):
            l.append(l1[m1])
            m1+=1
        elif(l1[m1]<l2[m2]):
            l.append(l1[m1])
            m1+=1
        elif(l2[m2]<=l1[m1]):
            l.append(l2[m2])
            m2+=1
    return l
def sort(l):
    n=len(l)
    if(n<=1):
        return l
    else:
        return merge(sort(l[0:n//2]),sort(l[n//2:n]))
l=[5,3,1,2,4]
l=sort(l)
print(l)