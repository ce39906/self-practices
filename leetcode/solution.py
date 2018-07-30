import json
def formLink(nj,index,val):
    lD={}
    if index==len(nj)-1:
        lD[NAME]=nj[index]
        lD[VAL]=val
    else:
        lD[NAME]=nj[index]
        lD[CHILDREN]=[]
        lD[CHILDREN].append(formLink(nj,index+1,val))
    return lD

def findRoot(nj,index,nList,val):
    flag=False
    nIdx=0
    for node in nList:
        if node[NAME]==nj[index]:
            flag=True
            break
        else:
            nIdx+=1
    if flag:
        if nList[nIdx].has_key(CHILDREN):
            if index!=len(nj)-1:
                findRoot(nj,index+1,nList[nIdx][CHILDREN],val)
            else:
                nList[nIdx][VAL]=val
                #pass
                #nList[nIdx][CHILDREN].append(formLink(nj,index)
        else:
            if index==len(nj)-1:
                nList[nIdx][VAL]=val
            else:
                nList[nIdx][CHILDREN]=[]
                nList[nIdx][CHILDREN].append(formLink(nj,index+1,val))
    else:
        nList.append(formLink(nj,index,val))
                

NAME='name'
VAL='val'
CHILDREN='children'
res=[]
f = open("file.csv","r")
lines=f.readlines()
for line in lines:
    L=line.split(',')
    val=L[1]
    LEnd=L[-1].split('\n')
    nj=LEnd[0].split('-')
    series=L[0]
    if len(res)==0:
        d={}
        tmp=[]
        d['series']=series
        findRoot(nj,0,tmp,val)
        d['data']=tmp
        res.append(d)
        #print res
    else:
        flag=False
        for i in res:
            if i['series']==series:
                flag=True
                findRoot(nj,0,i['data'],val)
                break
        if flag is False:
            temp={}
            tmp2=[]
            temp['series']=series
            findRoot(nj,0,tmp2,val)
            temp['data']=tmp2
            res.append(temp)

res = json.dumps(res)
print res