# coding: utf-8
__author__ = 'ce39906'
'''
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
'''
def getPermutation(n, k):
    if n==1:
        return '1'
    if n==2 and k==1:
        return '12'
    if n==2 and k==2:
        return '21'
    first=(k-1)/jiecheng(n-1)+1
    lastindex=(k-1)%jiecheng(n-1)+1
    last=getPermutation(n-1,lastindex)
    new=''
    for i in last:
        if int(i)>=first:
            new+=str(int(i)+1)
        else:
            new+=i
    return str(first)+new
def jiecheng(n):
    total=1
    i=1
    while i<=n:
        total*=i
        i+=1
    return total
print getPermutation(4,4)