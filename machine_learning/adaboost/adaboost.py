#-*- coding: utf-8 -*-
"""
File Name: adaboost.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2018-01-08 19:24:32
"""
from numpy import *

def loadSimpData():
    dataMat = matrix([[1.,2.1],[2.,1.1],[1.3,1.],[1.,1.],[2.,1.]])
    classLabels = [1.0,1.0,-1.0,-1.0,1.0]
    return dataMat,classLabels

def stumClassify(dataMatrix,dimen,threhVal,thresIneq):
    retArray = ones((shape(dataMatrix)[0],1))
    if thresIneq == 'lt':
        retArray[dataMatrix[:,dimen] <= threhVal ] =  -1.0
    else:
        retArray[dataMatrix[:,dimen] > threhVal ] =  -1.0
    return retArray


def buildStump(dataArr,classLabels,D):
    dataMatrix = mat(dataArr);labelMat = mat(classLabels).T
    m,n = shape(dataMatrix)
    numSteps = 10.0;bestStump = {};bestClassEst = mat(zeros((m,1)))
    minError = inf

    for i in range(n):
        rangeMin = dataMatrix[:,i].min();rangeMax = dataMatrix[:,i].max()
        stepSize = (rangeMax - rangeMin) / numSteps

        for j in range(-1,int(numSteps) + 1):
            for inequal in ['lt','gt']:
                threshVal = (rangeMin + float(j) * stepSize)
                predictedVals = stumClassify(dataMatrix,i,threshVal,inequal)
                errArr = mat(ones((m,1)))
                errArr[predictedVals == labelMat] = 0
                weightedError = D.T * errArr
                if weightedError < minError:
                    minError = weightedError
                    bestClassEst = predictedVals.copy()
                    bestStump['dim'] = i
                    bestStump['thresh'] = threshVal
                    bestStump['ineq'] = inequal

    return bestStump,minError,bestClassEst


def adaBoostTrainDS(dataArr,classLabels,numIt = 40):
    weakClassArr = []
    m = shape(dataArr)[0]
    D = mat(ones((m,1)) / m)

    aggClassEst = mat(zeros((m,1)))

    for i in range(numIt):
        bestStump,error,classEst = buildStump(dataArr,classLabels,D)
        #print "D:",D.T
        alpha = float(0.5 * log((1.0 - error) / max(error,1e-16)))
        bestStump['alpha'] = alpha

        weakClassArr.append(bestStump)
        #print "classEst: ",classEst.T
        expon = multiply(-1 * alpha * mat(classLabels).T,classEst)
        D = multiply(D,exp(expon))
        D = D / D.sum()

        aggClassEst += alpha * classEst
        #print "aggClassEst: " , aggClassEst.T

        aggErrors = multiply(sign(aggClassEst) != mat(classLabels).T,ones((m,1)))

        errorRate = aggErrors.sum() / m
        print "total error: ",errorRate,"\n"
        if errorRate == 0.0:
            break
    return weakClassArr,aggClassEst

def adaClassify(datToClass,classifierArr):
    dataMatrix = mat(datToClass)
    m = shape(dataMatrix)[0]
    aggClassEst = mat(zeros((m,1)))
    for i in range(len(classifierArr)):
        classEst = \
        stumClassify(dataMatrix,classifierArr[i]['dim'],classifierArr[i]['thresh'],classifierArr[i]['ineq'])
        aggClassEst += classifierArr[i]['alpha'] * classEst
        print aggClassEst
    return sign(aggClassEst)

def loadDataSet(fileName):
    numFeat = len(open(fileName).readline().split('\t'))
    dataMat = [];labelMat = []
    fr = open(fileName)
    for line in fr.readlines():
        lineArr = []
        curLine = line.strip().split('\t')
        for i in range(numFeat - 1):
            lineArr.append(float(curLine[i]))
        dataMat.append(lineArr)
        labelMat.append(float(curLine[-1]))
    return dataMat,labelMat

def plotROC(predStrenths,classLabels):
    import matplotlib.pyplot as plt
    cur = (1.0,1.0)
    ySum = 0.0
    # 正样本数
    numPosClas = sum(array(classLabels) == 1.0)
    xStep = 1 / float(numPosClas)
    yStep = 1 / float(len(classLabels) - numPosClas)

    sortedIndicies = predStrenths.argsort()

    fig = plt.figure()
    fig.clf()
    ax = plt.subplot()
    for index in sortedIndicies.tolist()[0]:
        if classLabels[index] == 1.0:
            delX = 0; delY = yStep
        else:
            delX = xStep;delY = 0
            ySum += cur[1]
        ax.plot([cur[0],cur[0]- delX],[cur[1],cur[1]-delY],c='b')
        cur = (cur[0]-delX,cur[1]-delY)
    ax.plot([0,1],[0,1],'b--')
    plt.xlabel('False positive Rate')
    plt.ylabel('True positive Rate')

    ax.axis([0,1,0,1])
    plt.show()
    print 'The area Under the Curve is: ',ySum * xStep

