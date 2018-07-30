# coding: utf-8
__author__ = 'ce39906'
'''
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
'''
def partition(s):
    def isP(s):
        if len(s)==1:
            return True
        i=0
        j=len(s)-1
        while i<=j:
            if s[i]!=s[j]:
                return False
            else:
                i+=1
                j-=1
        return True

    if len(s)==0:
        return [[]]
    if len(s)==1:
        return[[s]]
    result=[]
    beginindex=len(s)-1
    while beginindex>=0:
        if isP(s[beginindex:]):
            temp=[]
            for j in partition(s[:beginindex]):
                temp.append(j)
            for j in temp:
                j.append(s[beginindex:])
            result+=temp
        beginindex-=1

    return result