/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/23 19:13:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

const std::string RPN::_operations = "+-*/";

RPN& RPN::operator= ( const RPN& src )
{
    if (this != &src) _str = src._str;
    return *this;
}

int RPN::getRPN( bool debug )
{
    std::string token;
    std::istringstream iss(_str);
    std::stack<int> stax;
    int value, loops = 0;
    initOperatorMap();

    while (nextToken(iss, token))
    {
        if (!validToken(token)) throw std::runtime_error("Bad tokens");
        if (std::isdigit(token[0]))
        {
            std::istringstream iss_value(token);
            iss_value >> value;
            stax.push(value);
            if (debug)
            {
                std::cout << BOLDWHITE << "(" << loops++ << ") " << BOLDYELLOW << "Pushed " << value << ": " << stax << RESET << std::endl;
            }
        }
        else
        {
            int a, b, result;
            if (!stax.empty())
            {
                b = stax.top();
                stax.pop();
            }
            else throw std::runtime_error("Bad expression");
            if (!stax.empty())
            {
                a = stax.top();
                stax.pop();
            }
            else throw std::runtime_error("Bad expression");

            rpnOp op = _operatorMap[token[0]];
            if (token[0] == '/' && b == 0) throw std::runtime_error("Div by zero");
            result = op(a, b);
            stax.push(result);
            if (debug)
            {
                std::cout << BOLDWHITE << "(" << loops++ << ") " << BOLDMAGENTA << "Popped " << b << ", " << a << RESET << std::endl;
                std::cout << BOLDYELLOW << "      Pushed " << a << " " << token[0] << " " << b << " = "<< result << ": " << stax << RESET << std::endl;
            }
        }
    }
    if (stax.size() != 1) throw std::runtime_error("Bad expression");
    return stax.top();
}


bool RPN::nextToken( std::istringstream& iss, std::string& token )
{
    return static_cast<bool>(iss >> token);
}

bool RPN::validToken( std::string& token )
{
    return (token.size() == 1) && (std::isdigit(token[0]) || _operations.find(token[0]) != std::string::npos);
}

std::ostream& operator << ( std::ostream& os, const std::stack<int>& s )
{
    std::stack<int> stx = s;

    os << "{ ";
    while (stx.size())
    {
        os << stx.top() << " "; stx.pop();
    }
    os << "}";
    return os;
}