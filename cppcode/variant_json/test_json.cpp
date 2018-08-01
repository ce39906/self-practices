/*************************************************************************
    > File Name: test_json.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-31 19:26:17
 ************************************************************************/
#include <iostream>
#include "json.hpp"

using namespace json;

int main()
{
    Object obj;
    obj.values["string"] = "v1";
    obj.values["bool"] = True();
    obj.values["null"] = Null();
    obj.values["number"] = Number(9);
    
    Array arr;
    arr.values.emplace_back(Number(1.02));
    arr.values.emplace_back(Number(2.2));
    arr.values.emplace_back(Number(3));
    arr.values.emplace_back(True());
    arr.values.emplace_back(False());
    obj.values["array"] = std::move(arr);
    
    // json access
    std::cout << "Test json access.\n";
    const auto& arr1 = access::asArray(obj["array"]);
    std::cout << "first number in arr is "
        << access::asNumber(arr1.front()).value << std::endl;
    // json serialize to ostream 
    std::cout << "Test serialize to ostream.\n";
    serialize(std::cout, obj);
    std::cout << std::endl;
    // json serialize to string
    std::cout << "Test serialize to string.\n";
    std::string str;
    serialize(str, obj);
    std::cout << str << std::endl;

    return 0;
}
