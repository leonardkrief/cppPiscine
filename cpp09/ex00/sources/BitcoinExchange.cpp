/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:39:09 by lkrief            #+#    #+#             */
/*   Updated: 2023/09/05 12:30:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <limits>
#include <iomanip>

               /**/
      /********************/
/******** Date subclass ********/
      /********************/
               /**/

BitcoinExchange::Date::Date( const char* s ) : _date(s) { parseDate(_date); }

BitcoinExchange::Date::Date( const std::string& s ) : _date(s) { parseDate(_date); }

BitcoinExchange::Date::Date( const Date& d ) : _date(d._date), _valid(d._valid), _y (d._y), _m (d._m), _d (d._d) {}

BitcoinExchange::Date::~Date() {}

BitcoinExchange::Date& BitcoinExchange::Date::operator= ( const Date& src )
{
    if (this != &src)
    {
        _date = src._date;
        _valid = src._valid;
        _y = src._y;
        _m = src._m;
        _d = src._d;
    }
    return *this;
}

bool BitcoinExchange::Date::operator== ( const Date& src ) const
{
    return _y == src._y && _m == src._m && _d == src._d;
}

bool BitcoinExchange::Date::operator< ( const Date& src ) const
{
    if (!_valid || !src._valid) return false;
    else if (_y > src._y) return false;
    else if (_y == src._y && _m > src._m) return false;
    else if (_y == src._y && _m == src._m && _d >= src._d) return false;
    return true;
}

bool BitcoinExchange::Date::operator<= ( const Date& src ) const
{
    return (*this < src) || (*this == src);
}

bool BitcoinExchange::Date::operator> ( const Date& src ) const
{
    return !(*this <= src);
}

bool BitcoinExchange::Date::operator>= ( const Date& src ) const
{
    return !(*this < src);
}

std::ostream& operator<< ( std::ostream& os, const BitcoinExchange::Date& date )
{
    os << date.getDate();
    return os;
}

bool BitcoinExchange::Date::good() const { return _valid; };
std::string BitcoinExchange::Date::getDate() const { return _date; };

int BitcoinExchange::Date::parseToken(std::string& token, unsigned int len)
{
    int value;
    std::istringstream ss(token);

    if (!std::isdigit(token[0]) || (token.length() != len))
    {
        return -1;
    }
    ss >> value;
    if (ss.fail() || !ss.eof())
    {
        return -1;
    }
    return value;
}

void BitcoinExchange::Date::parseDate(const std::string& date) 
{
    std::stringstream ss(date);
    std::string token;
    struct tm tm;

    std::getline(ss, token, '-');
    _y = parseToken(token, 4);
    std::getline(ss, token, '-');
    _m = parseToken(token, 2);
    std::getline(ss, token, '-');
    _d = parseToken(token, 2);

    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_year = _y - 1900; // Years start at 1900
    tm.tm_mon = _m - 1;     // Months start at 0 (Jan = 0, Dec = 11)
    tm.tm_mday = _d;        // Day beween 1-31
    tm.tm_isdst = -1;       // Daylight saving time (related to summer/winter time, + or - 1h)
    mktime(&tm);

    _valid = (tm.tm_year == _y - 1900) && (tm.tm_mon == _m - 1) && (tm.tm_mday == _d)
        && (tm.tm_year >= 0) && (tm.tm_mon >= 0) && (tm.tm_mday >= 1);
}

            /**/
    /********************/
/** PriceHistory subclass **/
    /********************/
            /**/

BitcoinExchange::PriceHistory::PriceHistory() : _file(""), _history(parseFile("")) {};
BitcoinExchange::PriceHistory::PriceHistory( const File file ) : _file(file), _history(parseFile(_file)) {};
BitcoinExchange::PriceHistory::PriceHistory( const PriceHistory& bph ) : _file(bph._file), _history(bph._history) {};
BitcoinExchange::PriceHistory::~PriceHistory() {};

BitcoinExchange::PriceHistory& BitcoinExchange::PriceHistory::operator= ( const PriceHistory& src )
{
    if (this != &src)
    {
        _file = src._file;
        _history = src._history;
    }
    return *this;
}

BitcoinExchange::PriceHistory::BitcoinRate BitcoinExchange::PriceHistory::getClosestRate( const BitcoinExchange::Date& d ) const
{
    std::ostringstream oss;

    // check for exact date
    std::map<BitcoinExchange::Date, BitcoinExchange::PriceHistory::BitcoinRate>::const_iterator it = _history.find(d);
    if (it != _history.end())
    {
        return it->second;
    }

    // exact date not found
    // upper_bound function finds the date immediately after d in _history
    std::map<BitcoinExchange::Date, BitcoinExchange::PriceHistory::BitcoinRate>::const_iterator it_upper = _history.upper_bound(d);
    if (it_upper == _history.begin())
    {
        oss << "DATE: too early => '" << d << "'";
        throw std::range_error(oss.str());
    }
    --it_upper;
    return it_upper->second;
}

std::map<BitcoinExchange::Date, BitcoinExchange::PriceHistory::BitcoinRate>
    BitcoinExchange::PriceHistory::parseFile( const BitcoinExchange::PriceHistory::File& file )
{
    std::fstream fstrm(file.c_str(), std::ios::in);
    if (!fstrm)
    {
        throw std::runtime_error("BTC PRICE HISTORY FILE: Failed to open file.");
    }

    std::map<BitcoinExchange::Date, BitcoinExchange::PriceHistory::BitcoinRate> history;
    std::string line;
    std::ostringstream oss;

    try
    {
        oss.str("");
        oss.clear();
        if (!std::getline(fstrm, line) || line != "date,exchange_rate")
        {
            oss << BOLDRED << "Price History invalid format: first line should be 'date,exchange_rate'." << RESET;
            throw std::runtime_error(oss.str());
        }
        while (std::getline(fstrm, line))
        {
            std::istringstream iss(line);
        
            // extracting the date
            std::string date_str;
            if (!std::getline(iss, date_str, ','))
            {
                continue;
            }
            Date date(date_str);
            if (!date.good())
            {
                continue;
            }

            // extracting the rate
            std::string rate_str;
            if (!std::getline(iss, rate_str))
            {
                continue;
            }
            BitcoinExchange::PriceHistory::BitcoinRate rate;
            std::istringstream ss(rate_str);
            if (!(ss >> rate))
            {
                continue;
            }

            history.insert(std::make_pair(date, rate));
        }
    }
    catch (std::runtime_error& e)
    {
        std::cerr << BOLDRED << e.what() << RESET;
    }
    return history;
}

               /**/
      /********************/
/* BitcoinExchange subclass */
      /********************/
               /**/

BitcoinExchange::BitcoinExchange() : _bph(""), _file("") {};
BitcoinExchange::BitcoinExchange(const PriceHistory::File ph_file) : _bph(PriceHistory(ph_file)), _file("") {};
BitcoinExchange::BitcoinExchange(const PriceHistory::File ph_file, const EvaluationFile eval_file) : _bph(PriceHistory(ph_file)), _file(eval_file) {};
BitcoinExchange::BitcoinExchange( const BitcoinExchange& src ) : _bph(src._bph), _file(src._file) {};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator= ( const BitcoinExchange& src )
{
    if (this != &src)
    {
        _bph = src._bph;
        _file = src._file;
    }
    return *this;
}

bool BitcoinExchange::checkHeader( const std::string& line )
{
    return (line == "date | value" ? true : false) ;
}

bool BitcoinExchange::checkBlankLine( const std::string& line )
{
    return (line == "" ? true : false) ;
}

BitcoinExchange::Date BitcoinExchange::parseDate( std::string& date_str )
{
    std::ostringstream oss;

    if (!isblank(date_str[date_str.size() - 1]))
    {
        oss << "DATE: missing end space => '" << date_str << "'" << RESET;
        throw std::runtime_error(oss.str());
    }
    date_str.erase(date_str.size() - 1);

    Date date(date_str);
    if (!date.good())
    {
        oss << "DATE: bad date or bad format => '" << date_str << "'" << RESET;
        throw std::runtime_error(oss.str());
    }

    return date;
}

BitcoinExchange::BtcAmmount BitcoinExchange::parseBtcAmmount( std::string& btc_str )
{
    std::ostringstream oss;

    if(!isblank(btc_str[0]))
        oss << "BTC: missing first space => '" << btc_str << "'";
    else if (btc_str.size() > 13)
        oss << "BTC: input too long => '" << btc_str << "'";
    if (oss.str().size()) throw std::runtime_error(oss.str());
    btc_str.erase(0,1);

    BtcAmmount btc;
    std::istringstream iss(btc_str);
    if ((!std::isdigit(btc_str[0]) && btc_str[0] != '-') || !(iss >> btc))
        oss << "BTC: unexpected characters => '" << btc_str << "'";
    else if (btc < 0)
        oss << "BTC: not a positive number => '" << btc << "'";
    else if (!iss.eof())
    {
        std::string remaining;
        std::getline(iss, remaining);
        oss << "BTC: unexpected remainings => '" << remaining << "'";
    }
    else if (btc > 1000)
        oss << "BTC: number too large => '" << std::setprecision(12) << btc << "'";
    if (oss.str().size()) throw std::runtime_error(oss.str());

    return btc;
}

void BitcoinExchange::evaluate(bool debug) const
{
    std::fstream fstrm(_file.c_str(), std::ios::in);
    if (!fstrm) throw std::runtime_error("BTC EVALUATION FILE: Failed to open file.");

    std::string line;
    std::ostringstream oss;

    try
    {
        oss.str("");
        oss.clear();
        if (!std::getline(fstrm, line) || !checkHeader(line))
        {
            oss << BOLDRED << "Invalid format: first line should be 'date | value'." << RESET;
            throw std::runtime_error(oss.str());
        }
        while (std::getline(fstrm, line))
        {
            oss.str("");
            oss.clear();
            try
            {
                std::istringstream ss(line);

                // Checking blank line
                if (checkBlankLine(line))
                {
                    continue;
                }

                // Print if debug mode ON
                if (debug) std::cout << std::left << std::setw(29) << line;

                // Checking the date
                std::string date_str;
                if (!std::getline(ss, date_str, '|'))
                {
                    oss << "DATE: unexpected parsing error.";
                    throw std::runtime_error(oss.str());
                }
                Date date(parseDate(date_str));

                // Checking the btc number
                std::string btc_str;
                if (!std::getline(ss, btc_str))
                {
                    oss << "BTC: unexpected parsing error.";
                    throw std::runtime_error(oss.str());
                }
                BtcAmmount btc(parseBtcAmmount(btc_str));

                BitcoinExchange::PriceHistory::BitcoinRate rate = _bph.getClosestRate(date);

                std::cout << BOLDGREEN << date << " => " << btc << " * " << rate << " = "
                    << std::setprecision(12) << btc * rate << "\n" << RESET;
            }
            catch (const std::range_error& e)
            {
                std::cerr << BOLDRED << e.what() << '\n' << RESET;
            }
            catch (const std::exception& e)
            {
                std::cerr << BOLDRED << e.what() << '\n' << RESET;
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << BOLDRED << e.what() << '\n' << RESET;
    }
}
