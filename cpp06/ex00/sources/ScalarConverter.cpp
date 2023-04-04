/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 03:38:20 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
bool ScalarConverter::_charValueExist = false;
bool ScalarConverter::_intValueExist = false;
bool ScalarConverter::_floatValueExist = false;
bool ScalarConverter::__VERBOSE__ = false;

ScalarConverter::ScalarConverter()
{
    if (ScalarConverter::__PRINT__LOG__)
    {
        std::cout << "[" << (void*)this
            << "] ScalarConverter default constructor called" << std::endl;
    }
}

ScalarConverter::ScalarConverter( const ScalarConverter& s )
{
    *this = s;
    if (ScalarConverter::__PRINT__LOG__)
    {
        std::cout << "[" << (void*)this
            << "] ScalarConverter copy constructor called" << std::endl;
    }
}

ScalarConverter::~ScalarConverter()
{
    if (ScalarConverter::__PRINT__LOG__)
    {
        std::cout << "[" << (void*)this
            << "] ScalarConverter destructor called" << std::endl;
    }
}


ScalarConverter& ScalarConverter::operator=( const ScalarConverter& s )
{
    (void)s;
    if (ScalarConverter::__PRINT__LOG__)
    {
        std::cout << "[" << (void*)this
            << "] ScalarConverter copy assignment operator called"
            << std::endl;
    }
    return *this;
}

bool ScalarConverter::isChar( const std::string& input )
{
    if (input.size() == 1 && !(input[0] >= '0' && input[0] <= '9'))
        return true;
    else if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    return false;
}

bool ScalarConverter::isInt( const std::string& input )
{
    int intValue;
    std::istringstream iss(input);

    if (input.empty())
        return false;
    iss >> intValue;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

bool ScalarConverter::isFloat( const std::string& input )
{
    float floatValue;
    std::size_t pos = input.find(".");
    std::string str(input);

    if (input == "nanf" || input == "-inff" || input == "+inff")
        return true;
    if (input.empty() || pos + 3 > input.size()
        || input.back() != 'f')
        return false;

    str.pop_back();
    std::istringstream iss(str);
    iss >> floatValue;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

bool ScalarConverter::isDouble( const std::string& input )
{
    double doubleValue;
    std::size_t pos = input.find(".");
    std::istringstream iss(input);

    if (input == "nan" || input == "-inf" || input == "+inf")
        return true;
    if (input.empty() || pos + 2 > input.size())
        return false;
    iss >> doubleValue;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

char ScalarConverter::toChar( const std::string& input )
{
    if (input.size() == 1)
        return input[0];
    return input[1];
}

int ScalarConverter::toInt( const std::string& input )
{
    int intValue;
    std::istringstream iss(input);

    iss >> intValue;
    if (iss.fail())
        throw std::ios_base::failure("Failed to read from input.");
    return intValue;
}

float ScalarConverter::toFloat( const std::string& input )
{
    float floatValue;
    std::istringstream iss(input.substr(0, input.size() - 1));

    if (input == "nan")
        return std::numeric_limits<float>::quiet_NaN();
    else if (input == "-inf")
        return -std::numeric_limits<float>::infinity();
    else if (input == "+inf")
        return std::numeric_limits<float>::infinity();

    iss >> floatValue;
    if (iss.fail())
        throw std::ios_base::failure("Failed to read from input.");
    return floatValue;
}

double ScalarConverter::toDouble( const std::string& input )
{
    double doubleValue;
    std::istringstream iss(input);

    if (input == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    else if (input == "-inf")
        return -std::numeric_limits<double>::infinity();
    else if (input == "+inf")
        return std::numeric_limits<double>::infinity();

    iss >> doubleValue;
    if (iss.fail())
        throw std::ios_base::failure("Failed to read from input.");
    return doubleValue;
}

void ScalarConverter::convertChar( char c )
{
    _char = c;
    _int = static_cast<int>(c);
    _float = static_cast<float>(c);
    _double = static_cast<double>(c);
    _charValueExist = true;
    _intValueExist = true;
    _floatValueExist = true;
}

void ScalarConverter::convertInt( int i )
{
    _char = static_cast<char>(i);
    _int = i;
    _float = static_cast<float>(i);
    _double = static_cast<double>(i);
    if (i >= 0 && i <= 255)
        _charValueExist = true;
    _intValueExist = true;
    _floatValueExist = true;
}

void ScalarConverter::convertFloat( float f )
{
    _char = static_cast<char>(f);
    _int = static_cast<int>(f);
    _float = f;
    _double = static_cast<double>(f);
    if (f >= 0 && f <= 255)
        _charValueExist = true;
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
        _intValueExist = true;
    _floatValueExist = true;
}

void ScalarConverter::convertDouble( double d )
{
    _char = static_cast<char>(d);
    _int = static_cast<int>(d);
    _float = static_cast<float>(d);
    _double = d;
    if (d >= 0 && d <= 255)
        _charValueExist = true;
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        _intValueExist = true;
    if (d >= std::numeric_limits<float>::lowest() && d <= std::numeric_limits<float>::max())
        _floatValueExist = true;
}

void ScalarConverter::displayChar()
{
    if (_charValueExist && _char >= 33 && _char <= 126)
        std::cout << "char : '" << _char << "'" << std::endl;
    else if (_charValueExist)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : impossible" << std::endl;
}

void ScalarConverter::displayInt()
{
    if (_intValueExist)
        std::cout << "int : " << _int << std::endl;
    else
        std::cout << "int : impossible" << std::endl;
}

void ScalarConverter::displayFloat()
{
    if (_floatValueExist)
    {
        std::cout << "float: ";
        if (std::isnan(_float))
            std::cout << "nanf";
        else if (std::isinf(_float))
            std::cout << (_float > 0 ? "+inff" : "-inff");
        else
            std::cout << std::fixed << std::setprecision(1) << _float << "f";
        std::cout << std::endl;
    }
    else
        std::cout << "float : impossible" << std::endl;
}

void ScalarConverter::displayDouble()
{
    std::cout << "double: ";
    if (std::isnan(_double))
        std::cout << "nanf";
    else if (std::isinf(_double))
        std::cout << (_double > 0 ? "+inf" : "-inf");
    else
        std::cout << std::fixed << std::setprecision(1) << _double;
    std::cout << std::endl;
}

void ScalarConverter::resetValues()
{
    ScalarConverter::_char = 0;
    ScalarConverter::_int = 0;
    ScalarConverter::_float = 0;
    ScalarConverter::_double = 0;
    ScalarConverter::_charValueExist = false;
    ScalarConverter::_intValueExist = false;
    ScalarConverter::_floatValueExist = false;
}

void ScalarConverter::convert( const std::string& input )
{
    resetValues();
    if (isChar(input))
    {
        verboseHeader(input, "CHAR");
        convertChar(toChar(input));
    }
    else if (isInt(input))
    {
        verboseHeader(input, "INT");
        convertInt(toInt(input));
    }
    else if (isFloat(input))
    {
        verboseHeader(input, "FLOAT");
        convertFloat(toFloat(input));
    }
    else if (isDouble(input))
    {
        verboseHeader(input, "DOUBLE");
        convertDouble(toDouble(input));
    }
    else
    {
        verboseHeader(input, "UNKNOWN");
        throw std::invalid_argument("Invalid input. No available conversion.");
    }
    displayChar();
    displayInt();
    displayFloat();
    displayDouble();
}

void ScalarConverter::verboseModeON()
{
    __VERBOSE__ = true;
}

// I discovered that some characters are 1-char wide but contain
// 2 or more chars. It is the case for UTF-8 encoded ones 
// like e.g. 'é' or 'ù'. Hence, my display gets un-aligned.
// To handle this properly I can use std::wstring but may not
// be compatible across all platforms.
// Best use is to use ICU or Boost.Locale.
int ScalarConverter::displayableStrings( std::string& i, std::string& d )
{
    if (i.size() > __HEADER__WIDTH__)
        i = " " + i.substr(0, __HEADER__WIDTH__ - 7) + "... ";
    if (d.size() > __HEADER__WIDTH__)
        d = " " + d.substr(0, __HEADER__WIDTH__ - 7) + "... ";
    int len = d.size() > i.size() ? d.size() : i.size();
    if (i.size() < d.size())
    {
        i = std::string((len - i.size()) / 2, ' ') + i;
        i = i + std::string(len - i.size(), ' ');
    }
    else if (d.size() < i.size())
    {
        d = std::string((len - d.size()) / 2, ' ') + d;
        d = d + std::string(len - d.size(), ' ');
    }
    return len;
}

// If I used wstrings,
// I should use std::wcout instead of std::cout.
// string litterals should be written L"***" instead of "***".
void ScalarConverter::verboseHeader( const std::string& input, const std::string& type )
{
    if (__VERBOSE__)
    {
        static bool first = true;
        std::string inp = " Input: " + input + " ";
        std::string det = " Detected type: " + type + " ";
        int w = __HEADER__WIDTH__;
        int len = displayableStrings(inp, det);

        if (!first)
            std::cout << std::endl;
        std::cout << std::setfill('=');
        std::cout << std::setw(w) << "" << std::endl;
        std::cout
            << std::setw(w / 2) << std::right << inp.substr(0, len / 2)
            << std::setw(w - w / 2) << std::left << inp.substr(len / 2, len - len / 2)
            << std::endl;
        std::cout
            << std::setw(w / 2) << std::right << det.substr(0, len / 2)
            << std::setw(w - w / 2) << std::left << det.substr(len / 2, len - len / 2)
            << std::endl;
        std::cout << std::setw(w) << "" << std::endl;
        first = false;
    }
}
