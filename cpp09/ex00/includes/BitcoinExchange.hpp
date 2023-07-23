/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:25:49 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/23 15:30:52 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
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
/* CLASS */
 /********/
class BitcoinExchange
{
    public:
        class Date
        {
            public:
                Date( const char* s ) : _date(s) { parseDate(_date); };
                Date( const std::string s = "") : _date(s) { parseDate(_date); };
                Date( const Date& d ) : _date(d._date), _valid(d._valid), _y (d._y), _m (d._m), _d (d._d) {};
                ~Date() {};
                Date& operator= ( const Date& src );
    
                bool operator== ( const Date& src ) const;
                bool operator< ( const Date& src ) const;
                bool operator<= ( const Date& src ) const;
                bool operator> ( const Date& src ) const;
                bool operator>= ( const Date& src ) const;

                bool good() const { return _valid; };
                std::string getDate() const { return _date; };

            private:
                std::string _date;
                bool _valid;
                int _y;
                int _m;
                int _d;

                int parseToken(std::string& token, unsigned int len);
                void parseDate( const std::string& date );
        };


        class PriceHistory
        {
            public:

                typedef double BitcoinRate;
                typedef std::string File;

                PriceHistory() : _file(""), _history(parseFile("")) {};
                PriceHistory( const File file ) : _file(file), _history(parseFile(_file)) {};
                PriceHistory( const PriceHistory& bph ) : _file(bph._file), _history(bph._history) {};
                ~PriceHistory() {};
                PriceHistory& operator= ( const PriceHistory& src );

                BitcoinRate getClosestRate( const Date& d ) const;

            private:
                File _file;
                std::map<Date, BitcoinRate> _history;

                static std::map<Date, BitcoinRate> parseFile( const File& file );
        
        };

        typedef std::string EvaluationFile;
        typedef double BtcAmmount;

        BitcoinExchange() : _bph(""), _file("") {};
        BitcoinExchange(const PriceHistory::File ph_file) : _bph(PriceHistory(ph_file)), _file("") {};
        BitcoinExchange(const PriceHistory::File ph_file, const EvaluationFile eval_file) : _bph(PriceHistory(ph_file)), _file(eval_file) {};
        BitcoinExchange( const BitcoinExchange& src ) : _bph(src._bph), _file(src._file) {};
        ~BitcoinExchange() {};
        BitcoinExchange& operator= ( const BitcoinExchange& src );

        void evaluate(bool debug = false) const;

    private:
        PriceHistory _bph;
        EvaluationFile _file;

        static bool skipLine( const std::string& line );
        static Date parseDate( std::string& date_str );
        static double parseBtcAmmount( std::string& btc_str );

};

std::ostream& operator<< ( std::ostream& os, const BitcoinExchange::Date& date );


#endif