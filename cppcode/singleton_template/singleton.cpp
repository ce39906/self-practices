/*************************************************************************
    > File Name: singleton.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2017-06-22 17:27:14
 ************************************************************************/
#include<iostream>
#include "singleton.h"
using namespace std;

class A
{
  public:
    A()
    {
        cout << "A constuct" << endl;
    }
    ~A()
    {
    }
};

int main()
{
    A* p1 = &util::Singleton<A>::instance();
    A* p2 = &util::Singleton<A>::instance();
    return 0;
}
