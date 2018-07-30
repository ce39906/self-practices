# coding: utf-8
__author__ = 'ce39906'
'''
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
'''
def search(A,target):
    if len(A)==0:
        return -1
    if len(A)==1:
        if A[0]==target:
            return 0
        else:
            return -1
    for i in range(len(A)-1):
        if A[i]>A[i+1]:
            break
    pivot=i
    print pivot
    leftlow=0
    lefthigh=pivot
    while leftlow<=lefthigh:
        lmid=(leftlow+lefthigh)/2
        if A[lmid]==target:
            return lmid
        elif A[lmid]<target:
            leftlow=lmid+1
        else:
            lefthigh=lmid-1
    rightlow=pivot+1
    righthigh=len(A)-1
    while rightlow<=righthigh:
        rmid=(rightlow+righthigh)/2
        if A[rmid]==target:
            return rmid
        elif A[rmid]<target:
            rightlow=rmid+1
        else:
            righthigh=rmid-1
    return -1
A=[4,5,6,7,0,1,2]
print search(A,4)