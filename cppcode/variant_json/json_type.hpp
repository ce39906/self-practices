/*************************************************************************
    > File Name: json_type.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-31 16:25:59
 ************************************************************************/
#ifndef JSON_TYPE_HPP
#define JSON_TYPE_HPP

#include <boost/variant.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace json
{

struct Object;
struct Array;

struct String
{
    String() {}
    String(const char* value) : value{value} {}
    String(std::string value) : value{std::move(value)} {}
    std::string value;
};

struct Number
{
    Number() {};
    Number(const double value) : value{value} {}
    double value;
};

struct True
{
};

struct False
{
};

struct Null
{
};

using Value = boost::variant<String,
                             Number,
                             boost::recursive_wrapper<Object>,
                             boost::recursive_wrapper<Array>,
                             True,
                             False,
                             Null>;

struct Object
{
    bool isMember(const std::string& key) const
    {
        return values.count(key) != 0;
    }

    const Value& at(const std::string& key) const
    {
        return values.at(key);
    }
    
    const Value& operator[](const std::string& key) const
    {
        return values.at(key);
    }

    std::unordered_map<std::string, Value> values;
};

struct Array
{
    const Value& at(const size_t idx) const
    {
        return values.at(idx);
    }
    
    const Value& operator[](const size_t idx) const
    {
        return values.at(idx);
    }

    size_t size() const
    {
        return values.size();
    }
    
    const Value& front() const
    {
        return values.front();
    }

    const Value& back() const
    {
        return values.back();
    }

    std::vector<Value> values;
};
} // ns json
#endif
