/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 03:24:21 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
    typedef bool (*isType)( const std::string& input );
    typedef void (*displayType)( const std::string& input );

    public:
        static void convert( const std::string& input );
        static void verboseModeON();

    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter& s );
        ScalarConverter& operator=( const ScalarConverter& s );
        ~ScalarConverter();

        static bool isChar( const std::string& input );
        static bool isInt( const std::string& input );
        static bool isFloat( const std::string& input );
        static bool isDouble( const std::string& input );

        static char toChar( const std::string& input );
        static int toInt( const std::string& input );
        static float toFloat( const std::string& input );
        static double toDouble( const std::string& input );

        static void convertChar( char c );
        static void convertInt( int i );
        static void convertFloat( float f );
        static void convertDouble( double d );

        static void displayChar();
        static void displayInt();
        static void displayFloat();
        static void displayDouble();

        static char _char;
        static int _int;
        static float _float;
        static double _double;

        static bool _charValueExist;
        static bool _intValueExist;
        static bool _floatValueExist;

        static void resetValues();
        static void verboseHeader( const std::string& input, const std::string& type );
        static int displayableStrings( std::string& i, std::string& d );

        static bool __VERBOSE__;
        const static bool __PRINT__LOG__ = false;
        const static int __HEADER__WIDTH__ = 60;
};


#endif