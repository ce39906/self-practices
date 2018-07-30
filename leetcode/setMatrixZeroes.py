# coding: utf-8
__author__ = 'ce39906'
'''
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
'''
def setZeroes(matrix):
    #不占用额外空间 的话，采取的方法是在第一行和第一列储存状态
    #并对matrix[0][0]座特殊处理
    #第二遍根据状态跟新矩阵
    row=len(matrix)
    col=len(matrix[0])
    col0=1#用来记录第一列的状态
    for i in range(row):
        if matrix[i][0]==0:
            col0=0
        for j in range(1,col):
            if matrix[i][j]==0:
                matrix[i][0]=matrix[0][j]=0
    #第二次 根据状态跟新
    for i in range(row-1,-1,-1):
        for j in range(col-1,0,-1):
            if matrix[i][0]==0 or matrix[0][j]==0:
                matrix[i][j]=0
        if col0==0:
            matrix[i][0]=0