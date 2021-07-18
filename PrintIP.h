/** @file
 * @brief This file contains implementation of PrintIP
 * functions for Integers, Strings and Containers.
 */
#pragma once

#include <vector>
#include <iostream>
#include <list>

static const char Delimiter = '.';
static const int8_t byteSize = 8;

/**
 * @brief Represents input value in bytes or leaves it as it is
 * depending on the value type.
 *
 * @param value is integer to represent
 * @return std::vector<std::string> for testing purposes we return vector
 */

/**
 * @brief Represents integer value in bytes.
 * Specialization of printIP func for integer types.
 */

template <typename Val_t,
    typename = std::enable_if_t<std::is_integral<Val_t>::value>>
std::vector<std::string> printIP(const Val_t& value)
{
    constexpr auto size = sizeof(Val_t);
    std::vector<std::string> res;
    res.reserve(size);

    for (int i = 0; i < size; i++)
    {
        const auto item = std::to_string(
                static_cast<unsigned char>(value >> ((size - i - 1) * byteSize)));
        res.emplace_back(item);
        std::cout << item;
        if (i != size - 1)
        {
            std::cout << Delimiter;
        }
    }
    std::cout << std::endl;
    return res;
}

/**
 * @brief Prints string as it is.
 * Specialization of printIP func for string.
 */

std::vector<std::string> printIP(const std::string& value)
{
    std::cout << value << std::endl;
    return {value};
}

template<typename Val_t>
concept HasBeginEnd = requires(Val_t value)
{
    value.begin();
    value.end();
};

/**
 * @brief Prints container dividing each element with dot.
 * Specialization of printIP func for vector or list container.
 */

template<typename Val_t, template<typename...> class Container,
    typename = std::enable_if_t<std::is_same_v<std::decay_t<Container<Val_t>>, std::vector<Val_t>>
    or std::is_same_v<std::decay_t<Container<Val_t>>, std::list<Val_t>>>>
std::vector<std::string> printIP(const Container<Val_t>& value)
{
    std::vector<std::string> res;
    res.reserve(value.size());

    for (auto i = value.begin(); i != value.end(); i++)
    {
        std::cout << std::to_string(*i);
        res.emplace_back(std::to_string(*i));
        if (i != std::prev(std::end(value)))
        {
            std::cout << Delimiter;
        }
    }
    std::cout << std::endl;

    return res;
}