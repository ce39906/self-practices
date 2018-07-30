# coding: utf-8
__author__ = 'ce39906'
'''
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
'''
def simplifyPath(path):
    pathArray=path.split('/')
    #print pathArray
    j=0
    while j<len(pathArray):
        if len(pathArray[j])==0:
            del pathArray[j]
        else:
            j+=1
    print pathArray
    if pathArray==[]:
        return '/'
    stack=[]
    for i in pathArray:
        if i!='..' and i!='.':
            stack.append(i)
        elif i=='..':
            if len(stack)!=0:
                stack.pop()
    return '/'+'/'.join(stack)
path='/home/of/foo/../../bar/../../is/./here/.'
print simplifyPath(path)