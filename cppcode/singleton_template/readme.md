# About
a thread safe singleton template use c++11 ```call_once``` and ```once_flag```
# Compile 
> g++ -std=c++11 singleton.h main.cpp -lpthread

# Usage
```
A* p1 = &util::Singleton<A>::instance();
```
