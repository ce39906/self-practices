# coding: utf-8
__author__ = 'ce39906'
'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
Show Tags Array Hash Table
'''
def fourSum(num, target):
    d1={}
    result=[]
    num.sort()
    for i in range(len(num)):
        for j in range(i+1,len(num)):
            ijsum=num[i]+num[j]  #按照从小到大的顺序遍历，形成字典，保证字典的形成不会有遗漏
            if target-ijsum in d1:#对应的查找时是从大到小的顺序
                for (a,b) in d1[target-ijsum]:
                    if b<i and [num[a],num[b],num[i],num[j]] not in result:
                        result.append([num[a],num[b],num[i],num[j]])
            if ijsum in d1:
                d1[ijsum].append((i,j))
            else:
                tem=[]
                tem.append((i,j))
                d1[ijsum]=tem

    return result

num=[-493,-482,-482,-456,-427,-405,-392,-385,-351,-269,-259,-251,-235,-235,-202,-201,-194,-189,-187,-186,-180,-177,-175,-156,-150,-147,-140,-122,-112,-112,-105,-98,-49,-38,-35,-34,-18,20,52,53,57,76,124,126,128,132,142,147,157,180,207,227,274,296,311,334,336,337,339,349,354,363,372,378,383,413,431,471,474,481,492]
print fourSum(num,6189)