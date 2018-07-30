#-*- coding: utf-8 -*-
"""
File Name: bayes.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2018-01-07 10:55:45
"""
from numpy import *

def loadDataSet():
    postingList = [['my','dog','has','flea','problems','help','please'],
            ['maybe','not','take','him','to','dog','park','stupid'],
            ['my','dalmation','is','so','cute','I','love','him'],
            ['stop','posting','stupid','worthless','garbage'],
            ['mr','licks','ate','my','steak','how','to','stop','him'],
            ['quit','buying','worthless','dog','food','stupid']]
    classVec = [0,1,0,1,0,1]
    return postingList,classVec

# 建立词汇表
def createVocabList(dataSet):
    vocabSet = set([])
    for document in dataSet:
        vocabSet = vocabSet | set(document)
    return list(vocabSet)

def setOfWords2Vec(vocabList,inputSet):
    returnVec = [0] * len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] = 1
        else:
            print 'the word : %s is not in my vocablist' % word
    return returnVec

def trainNB0(trainMatrix,trainCategory):
    numTrainDocs = len(trainMatrix)
    numWords = len(trainMatrix[0])
    pAbusive = sum(trainCategory) / float(numTrainDocs)
    p0Num = ones(numWords)
    p1Num = ones(numWords)

    p0Denum = 2.0 ; p1Denum = 2.0

    for i in range((numTrainDocs)):
        if trainCategory[i] == 1:
            p1Num += trainMatrix[i]
            p1Denum += sum(trainMatrix[i])
        else:
            p0Num += trainMatrix[i]
            p0Denum += sum(trainMatrix[i])
    p1Vect = log(p1Num / p1Denum)
    p0Vect = log(p0Num / p0Denum)

    return p0Vect,p1Vect,pAbusive

def classifyNB(vec2Classify,p0Vec,p1Vec,pClass1):
    p1 = sum(vec2Classify * p1Vec) + log(pClass1)
    p0 = sum(vec2Classify * p0Vec) + log(1.0-  pClass1)

    if p1 > p0:
        return 1
    else:
        return 0

def testingNB():
    listOPosts,listClasses = loadDataSet()
    myVocablist = createVocabList(listOPosts)
    trainMat = []
    for postinDoc in listOPosts:
        trainMat.append(setOfWords2Vec(myVocablist,postinDoc))
    p0v,p1v,pAb = trainNB0(array(trainMat),array(listClasses))

    testEntry = ['love','my','dalmation']
    thisDoc = array(setOfWords2Vec(myVocablist,testEntry))
    print testEntry,'classified as: ',classifyNB(thisDoc,p0v,p1v,pAb)

    testEntry = ['stupid','garbage']
    thisDoc = array(setOfWords2Vec(myVocablist,testEntry))
    print testEntry,'classified as: ',classifyNB(thisDoc,p0v,p1v,pAb)
    
def bagOfWords2VecMN(vocabList,inputSet):
    returnVec = [0] * len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] += 1
    return returnVec


