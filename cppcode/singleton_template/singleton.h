/*************************************************************************
    > File Name: singleton.h
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2017-06-22 17:16:54
 ************************************************************************/
#ifndef SINGLETON_CPP
#define SINGLETON_CPP
#include "boost/noncopyable.hpp"
#include <mutex>
#include <memory>
namespace util
{
template<typename T>
class Singleton : boost::noncopyable
{
  public:
    static T& instance()
    {
        std::call_once(Singleton::ponce_,&Singleton::init);
        return *value_;
    }
  private:
    Singleton();
    ~Singleton();
    
    static void init()
    {
        value_ = new T();
    }
    
    static std::once_flag ponce_;
    static T* value_;
};

template<typename T>
std::once_flag Singleton<T>::ponce_;

template<typename T>
T* Singleton<T>::value_ = NULL;
}

#endif
