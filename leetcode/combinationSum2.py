# coding: utf-8
__author__ = 'ce39906'
'''
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
'''
def combinationSum2(candidates, target):
    candidates.sort()
    out=[]
    pool=[[]]
    for i in candidates[::-1]:
        newpool=[]
        for c in pool:
            new=c+[i]
            if sum(new)<target:
                newpool.append(new)
            elif sum(new)==target:
                new.sort()
                if new not in out:
                    out.append(new)
            else:
                continue
        pool+=newpool
    return out
can=[10,1,2,7,6,1,5]
tar=8
print combinationSum2(can,tar)