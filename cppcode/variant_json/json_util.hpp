/*************************************************************************
    > File Name: json_util.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-01 14:07:49
 ************************************************************************/
#ifndef JSON_UTIL_HPP
#define JSON_UTIL_HPP

#include "json_type.hpp"

#include <iomanip>
#include <sstream>

#include <boost/algorithm/string/trim.hpp>

namespace json
{
namespace util
{
namespace cast
{

template <typename T, int Percision = 6>
inline std::string to_string_with_percision(const T x)
{
    static_assert(std::is_arithmetic<T>::value, "intergral or floating point type required!");
    std::stringstream out;
    out << std::fixed << std::setprecision(Percision) << x;
    std::string value = out.str();
    
    boost::trim_right_if(value, boost::is_any_of("0"));
    boost::trim_right_if(value, boost::is_any_of("."));
    return value;
}

} // ns cast
} // ns util
} // ns json
#endif
