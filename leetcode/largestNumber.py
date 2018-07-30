def largestNumber(self, num):
    def largerone(s1,s2):
        string1=s1+s2
        string2=s2+s1
        if int(string1)>int(string2):
            return True
        else:
            return False
            
    if len(num)==1:
        return str(num[0])
    strnum=[]
    for i in num:
        strnum.append(str(i))
    #冒泡排序
    for i in range(len(strnum)):
        for j in range(i+1,len(strnum)):
            if largerone(strnum[i],strnum[j]):
                continue
            else:
                temp=strnum[i]
                strnum[i]=strnum[j]
                strnum[j]=temp
        
    result=''.join(strnum)
    if int(result)==0:
        return '0'
    else:
        return result