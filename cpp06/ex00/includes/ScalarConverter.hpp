/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 03:54:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
    public:
        static void convert( const std::string& input );
        static void verboseModeON();

    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter& s );
        ScalarConverter& operator=( const ScalarConverter& s );
        ~ScalarConverter();

        static char _char;
        static int _int;
        static float _float;
        static double _double;

        static bool _charValueExist;
        static bool _intValueExist;
        static bool _floatValueExist;

        static bool _isChar( const std::string& input );
        static bool _isInt( const std::string& input );
        static bool _isFloat( const std::string& input );
        static bool _isDouble( const std::string& input );

        static char _toChar( const std::string& input );
        static int _toInt( const std::string& input );
        static float _toFloat( const std::string& input );
        static double _toDouble( const std::string& input );

        static void _convertChar( char c );
        static void _convertInt( int i );
        static void _convertFloat( float f );
        static void _convertDouble( double d );

        static void _displayChar();
        static void _displayInt();
        static void _displayFloat();
        static void _displayDouble();

        static void _resetValues();
        static void _verboseHeader( const std::string& input, const std::string& type );
        static int _displayableStrings( std::string& i, std::string& d );

        static bool _verbose_;
        const static int _header_width_ = 60;
        const static bool _print_log_ = false;
};


#endif