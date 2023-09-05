/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/09/05 15:43:54 by lkrief           ###   ########.fr       */
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
    private:
        RPN();
        RPN( const RPN& src );
        RPN& operator= ( const RPN& src );

    public:
        RPN( const std::string& str );
        ~RPN();

        int getRPN( bool debug = false );

    private:
        // members
        std::string _str;
        static const std::string _operations;

        //features
        static bool nextToken( std::istringstream& iss, std::string& token );
        static bool validToken( std::string& token );

        // operators map
        typedef int (*rpnOp) (int, int);
        static std::map<char, rpnOp> _operatorMap;

        static int add ( int a, int b );
        static int sub ( int a, int b );
        static int mul ( int a, int b );
        static int div ( int a, int b );
        static void initOperatorMap();
};

std::ostream& operator << ( std::ostream& os, const std::stack<int>& s );

#endif
