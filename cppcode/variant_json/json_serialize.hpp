/*************************************************************************
    > File Name: json_serialize.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-31 17:23:19
 ************************************************************************/
#ifndef JSON_SERIALIZE_HPP
#define JSON_SERIALIZE_HPP

#include "json_type.hpp"
#include "json_util.hpp"

#include <vector>
#include <ostream>

namespace json
{

struct SerializeToOstream : boost::static_visitor<void>
{
    explicit SerializeToOstream (std::ostream& out) : out(out) {}

    void operator() (const String& string) const
    {
        out << "\"";
        out << string.value;
        out << "\"";
    }

    void operator() (const Number& number) const
    {
        out << util::cast::to_string_with_percision(number.value);
    }

    void operator() (const Object& object) const
    {
        out << "{";
        for (auto it = object.values.begin(); it != object.values.end();)
        {
            out << "\"" << it->first << "\":";
            boost::apply_visitor(SerializeToOstream(out), it->second);
            if (++it != object.values.end())
            {
                out << ",";
            }
        }
        out << "}";
    }
    
    void operator() (const Array& array) const
    {
        out << "[";
        for (auto it = array.values.cbegin(); it != array.values.cend();)
        {
            boost::apply_visitor(SerializeToOstream(out), *it);
            if (++it != array.values.cend())
            {
                out << ",";
            }
        }
        out << "]";
    }

    void operator() (const True&) const
    {
        out << "ture";
    }

    void operator() (const False&) const
    {
        out << "false";
    }

    void operator() (const Null&) const
    {
        out << "null";
    }

  private:
    std::ostream& out;
};

struct SerializeToString : boost::static_visitor<void>
{
    explicit SerializeToString (std::string& out) : out(out) {}
    
    void operator() (const String& string) const
    {
        out.push_back('\"');
        out.append(string.value);
        out.push_back('\"');
    }

    void operator() (const Number& number) const
    {
        const std::string number_str = util::cast::to_string_with_percision(number.value);
        out.append(std::move(number_str));
    }

    void operator() (const Object& object) const
    {
        out.push_back('{');
        for (auto it = object.values.begin(); it != object.values.end();)
        {
            out.push_back('\"');
            out.append(it->first);
            out.push_back('\"');
            out.push_back(':');
            boost::apply_visitor(SerializeToString(out), it->second);
            if (++it != object.values.end())
            {
                out.push_back(',');
            }
        }
        out.push_back('}');
    }
    
    void operator() (const Array& array) const
    {
        out.push_back('[');
        for (auto it = array.values.cbegin(); it != array.values.cend();)
        {
            boost::apply_visitor(SerializeToString(out), *it);
            if (++it != array.values.cend())
            {
                out.push_back(',');
            }
        }
        out.push_back(']');
    }

    void operator() (const True&) const
    {
        out.append("true");
    }

    void operator() (const False&) const
    {
        out.append("false");
    }

    void operator() (const Null&) const
    {
        out.append("null");
    }

  private:
    std::string& out;
};

void serialize(std::ostream& out, const Object& object)
{
    Value value = object;
    boost::apply_visitor(SerializeToOstream(out), value);
}

void serialize(std::string& out, const Object& object)
{
    Value value = object;
    boost::apply_visitor(SerializeToString(out), value);
}

} // ns json

#endif
