def swap(l,i,j):
    l[i],l[j]=l[j],l[i]
def partition(l,low,up):
    pivot=low+((up-low)//2)
    l[pivot],l[up]=l[up],l[pivot]
    pivot=up
    i=low
    j=up-1
    while(i<=j):
        if(l[i]<l[pivot]):
            i+=1
        elif(l[j]>l[pivot]):
            j-=1
        elif(i<j):                 # i<j, will bascially check l[i]>l[j] and greter than and less than pivot repectively 
                                   # since first and second if will check the complelement of this else if
                                   #  creiteira and since they have not passed them
                                   #they will come here
            swap(l,i,j)
            i+=1
            j-=1
    swap(l,pivot,i)
    return i
def sort(l,low,up):
    if(low<up):
        mid=partition(l,low,up)
        sort(l,low,mid-1)
        sort(l,mid+1,up)
l=[5,3,1,2,4]
sort(l,0,len(l)-1)
print(l)
