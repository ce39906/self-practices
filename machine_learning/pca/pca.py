#-*- coding: utf-8 -*-
"""
File Name: pca.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2018-01-16 10:43:04
"""
from numpy import *

def loadDataSet(fileName,delim='\t'):
    fr = open(fileName)
    stringArr = [line.strip().split(delim) for line in fr.readlines()]
    datArr = [map(float,line) for line in stringArr]
    return mat(datArr)

def pca(dataMat,topNfeat = 9999999):
    meanVals = mean(dataMat,axis = 0)
    meanRemoved = dataMat - meanVals
    covMat = cov(meanRemoved,rowvar = 0)
    eigVals,eigVects = linalg.eig(mat(covMat))
    eigValInd = argsort(eigVals)
    eigValInd = eigValInd[:-(topNfeat+1): -1]
    redEigVects = eigVects[:,eigValInd]
    lowDDataMat = meanRemoved * redEigVects
    reconMat = (lowDDataMat + redEigVects.T) + meanVals
    return lowDDataMat,reconMat

def replaceNanWithMean():
    dataMat = loadDataSet('secom.data',' ')
    numFeat = shape(dataMat)[1]
    for i in range(numFeat):
        meanVal = mean(dataMat[nonzero(~isnan(dataMat[:,i].A))[0],i])
        datMat[nonzero(isnan(dataMat[:,i].A))[0],i] = meanVal
    return datMat


