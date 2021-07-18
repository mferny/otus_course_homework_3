/** @file
 * @brief This file contains implementation of PrintIP
 * functions for Integers, Strings and Containers.
 */
#pragma once

#include <vector>
#include <iostream>
#include <concepts>

static const char Delimiter = '.';
static const int8_t byteSize = 8;

/**
 * @brief Represents input value in bytes or leaves it as it is
 * depending on the value type.
 *
 * @param value is integer to represent
 * @return std::vector<std::string> for testing purposes we return vector
 */

template<typename Val_t>
std::vector<std::string> printIP(const Val_t& value);

/**
 * @brief Represents integer value in bytes.
 * Specialization of printIP func for integer types.
 */

template<typename Val_t>
concept Integral = std::is_integral_v<Val_t>;

template<Integral Val_t>
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

template<typename Val_t>
concept String = std::same_as<Val_t, std::string>;

template<String Val_t>
std::vector<std::string> printIP(const Val_t& value)
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
 * Specialization of printIP func for containers.
 */

template<typename Val_t>
concept Container = HasBeginEnd<Val_t> and not String<Val_t>;

template<Container Val_t>
std::vector<std::string> printIP(const Val_t& ip)
{
    std::vector<std::string> res;
    res.reserve(ip.size());

    for (auto i = ip.begin(); i != ip.end(); i++)
    {
        std::cout << std::to_string(*i);
        res.emplace_back(std::to_string(*i));
        if (i != std::prev(std::end(ip)))
        {
            std::cout << Delimiter;
        }
    }
    std::cout << std::endl;

    return res;
}