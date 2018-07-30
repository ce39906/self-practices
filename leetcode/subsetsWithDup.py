# coding: utf-8
__author__ = 'ce39906'
'''
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
'''
def subsetsWithDup(S):
    def sub(s):
        res=[]
        for i in range(len(s)):
            if s[0:i]+s[i+1:] not in res:
                res.append(s[0:i]+s[i+1:])
        return res


    if len(S)==1:
        return [[],S]
    S.sort()
    if len(S)==2:
        if S[0]!=S[1]:
            return [[],[S[0]],[S[1]],S]
        else:
            return [[],[S[0]],S]
    j=len(S)-1
    result=sub(S)
    while j>=3:
        re1=[]
        for i in result:
            if len(i)==j:
                for k in sub(i):
                    if k not in re1:
                        re1.append(k)
        result+=re1
        j=j-1
    for i in S:
        if [[i]] not in result:
            result+=[[i]]
    result+=[[]]
    result+=[S]
    i=0
    while i<len(result):

        if result[i] in result[0:i]:
            del result[i]
        else:
            i+=1
    return result
S=[5,5,5,5,5]
print subsetsWithDup(S)