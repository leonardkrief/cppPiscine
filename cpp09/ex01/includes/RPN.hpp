/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/24 10:19:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <map>

 /********/
/* COLORS */
 /********/
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

 /********/
/* CLASS  */
 /********/
class RPN
{
    public:

        RPN( const std::string& str ) : _str(str) {} ;
        ~RPN() {} ;

        int getRPN( bool debug = false );

    private:
        // members
        std::string _str;
        static const std::string _operations;

        // operators map
        typedef int (*rpnOp) (int, int);
        std::map<char, rpnOp> _operatorMap;
        static int add ( int a, int b ) { return a + b; };
        static int sub ( int a, int b ) { return a - b; };
        static int mul ( int a, int b ) { return a * b; };
        static int div ( int a, int b ) { return a / b; };
        void initOperatorMap()
        {
            _operatorMap['+'] = &RPN::add;
            _operatorMap['-'] = &RPN::sub;
            _operatorMap['*'] = &RPN::mul;
            _operatorMap['/'] = &RPN::div;
        }

        // features
        RPN() : _str() {} ;
        RPN( const RPN& src ) : _str(src._str) {} ;
        RPN& operator= ( const RPN& src );

        static bool nextToken( std::istringstream& iss, std::string& token );
        static bool validToken( std::string& token );
};

std::ostream& operator << ( std::ostream& os, const std::stack<int>& s );

#endif


/*

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

./RPN "7 7 * 7 -"
42

./RPN "1 2 * 2 / 2 * 2 4 - +"
0

./RPN "(1 + 1)"
Error

*/