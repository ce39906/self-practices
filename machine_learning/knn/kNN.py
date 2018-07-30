#-*- coding: utf-8 -*-
"""
File Name: kNN.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2018-01-06 16:10:39
"""
from numpy import *
import operator

def createDataSet():
    group = array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]])
    labels = ['A','A','B','B']
    return group,labels

def classify0(inX,dataSet,labels,k):
    dataSetSize = dataSet.shape[0]
    diffMat = tile(inX,(dataSetSize,1)) - dataSet
    sqDiffMat = diffMat**2
    # 按照行求和
    sqDistance = sqDiffMat.sum(axis = 1)
    distances = sqDistance ** 0.5
    # argsort 返回的是数组值从小到大的索引值
    sortedDistIndicies = distances.argsort()

    classCount = {}

    for i in range(k):
        voteIlabel = labels[sortedDistIndicies[i]]
        # vote count ++
        classCount[voteIlabel] = classCount.get(voteIlabel,0) + 1
    # 按照投票数大小倒序排序
    sortedClassCount = sorted(classCount.iteritems(),key =
            operator.itemgetter(1),reverse = True)
    return sortedClassCount[0][0]

def file2matrix(filename):
    fr = open(filename)
    arraryOLines = fr.readlines()
    numberOfLines = len(arraryOLines)
    returnMatrix = zeros((numberOfLines,3))
    classLabelVector = []
    index = 0
    for line in arraryOLines:
        line = line.strip()
        listFromLine = line.split('\t')
        returnMatrix[index,:] = listFromLine[0:3]
        classLabelVector.append(int(listFromLine[-1]))
        index += 1
    return returnMatrix,classLabelVector
'''
对样本数据进行归一化
newValue = (oldValue - min) / (max - min)
'''
def autoNorm(dataSet):
    minVals = dataSet.min(0)
    maxVals = dataSet.max(0)
    ranges = maxVals - minVals
    normDataSet = zeros(shape(dataSet))
    m = dataSet.shape[0]
    normDataSet = dataSet - tile(minVals,(m,1))
    normDataSet = normDataSet / tile(ranges,(m,1))
    return normDataSet,ranges,minVals

'''
对分类的结果进行测试
'''
def datingClassTest():
    # 调整测试集的数目
    hoRatio = 0.10
    datingDataMat,datingLabels = file2matrix('datingTestSet.txt')
    normMat,ranges,minVals = autoNorm(datingDataMat)
    m = normMat.shape[0]
    numTestVecs = int(m * hoRatio)
    errorCount = 0.0

    for i in range(numTestVecs):
        classifierResult =
        classify0(normMat[i,:],normMat[numTestVecs:m,:],datingLabels[numTestVecs:m,:],3)
        if (classifierResult != datingLabels[i]):
            errorCount += 1.0
    print 'the total error rate is : %f' % (errorCount / float(numTestVecs))

if __name__ == '__main__':
    group,labels = createDataSet()
    predict = classify0([0,0],group,labels,3)
    print predict
