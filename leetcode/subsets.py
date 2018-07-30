# coding: utf-8
__author__ = 'ce39906'
'''
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
'''
def subsets(S):
    solutions=[]
    S.sort()
    bits=len(S) #表示一共有多少位
    for i in range(1<<bits): #移位运算，1<<bits 表示2的bits次幂
        solution=[]
        for j in range(bits):
            if i&(1<<j):#第j位上为1时就把其加入solution
                solution.append(S[j])
        solutions.append(solution)
    return solutions


S=[1,2,3,4,5,6,7,8,9,0]
print subsets(S)