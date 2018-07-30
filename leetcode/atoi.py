# coding: utf-8
__author__ = 'ce39906'
def atoi(str):
    isnegitive=False
    result=0
    i=0
    while i<len(str):
        if str[i]==' ':
            i+=1
        elif str[i]=='+':
            i+=1
            break
        elif str[i]=='-':
            isnegitive=True
            i+=1
            break
        elif ord(str[i])>=48 and ord(str[i])<=57:
            break
        else:
            return 0
    while i<len(str):
        if ord(str[i])<48 or ord(str[i])>57:
            break
        else:
            result=result*10+(ord(str[i])-48)
            i+=1
    if isnegitive:
        result=-result
    if result>2147483647:
        return 2147483647
    if result<-2147483648:
        return -2147483648
    return result
str=" b11228552307"
print atoi(str)