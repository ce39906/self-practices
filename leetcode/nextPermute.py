# coding=utf-8
__author__ = 'ce39906'

def permuteUnique(nums):
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [nums]
        res = []
        begin = [x for x in nums]
        res.append(begin)
        nextPermute(nums)
        print res
        while nums!=begin:
            temp = [x for x in nums]
            res.append(temp)
            nextPermute(nums)
        return res
def nextPermute(nums):
        #一找一换三反转
    res =[]
    if len(nums)==0:
        return []
    if len(nums)==1:
        return [nums]
    i=len(nums)-2
    j=len(nums)-1
    while i>=0:
        if nums[i]<nums[i+1]:
            break
        i-=1
    if i<0:
        rever(nums,0,len(nums)-1)
        return
    while j>i:
        if nums[j]>nums[i]:
            break
        j-=1
    temp = nums[i]
    nums[i] = nums[j]
    nums[j] = temp
    rever(nums,i+1,len(nums)-1)
def rever(nums,begin,end):
    if begin == end:
        return
    while begin<end:
        temp=nums[begin]
        nums[begin]=nums[end]
        nums[end]=temp
        begin+=1
        end-=1

test = [0,1,0,0,9]
print permuteUnique(test)
#print nextPermute(test)
#print test