/*************************************************************************
    > File Name: json.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-01 15:32:10
 ************************************************************************/
#ifndef JSON_HPP
#define JSON_HPP

#include "json_type.hpp"
#include "json_serialize.hpp"

namespace json
{
// fwd declaration
struct Object;
struct Array;
struct String;
struct Number;
struct True;
struct False;
struct Null;
 
void serialize(std::ostream& out, const Object& object);

void serialize(std::string& out, const Object& object);

namespace access
{

inline const Object& asObject(const Value& value)
{
    return boost::get<Object>(value);
}

inline const Array& asArray(const Value& value)
{
    return boost::get<Array>(value);
}

inline const String& asString(const Value& value)
{
    return boost::get<String>(value);
}

inline const Number& asNumber(const Value& value)
{
    return boost::get<Number>(value);
}

inline const True& asTrue(const Value& value)
{
    return boost::get<True>(value);
}

inline const False& asFalse(const Value& value)
{
    return boost::get<False>(value);
}

inline const Null& asNull(const Value& value)
{
    return boost::get<Null>(value);
}

} // ns access

} // ns json
#endif
