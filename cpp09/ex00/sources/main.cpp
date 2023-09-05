/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/09/04 13:11:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>

// const unsigned int BANNER_SIZE = 55;

// static void printTitle(std::string title, std::string color = YELLOW, bool toUpper = true, int banner_size = BANNER_SIZE)
// {
//     static int first;
//     if (first > 0)
//         std::cout << std::endl;
//     else
//         first++;

//     title = " " + title + " ";
//     if (toUpper)
//     {
//         for (int i = 0; title[i]; i++)
//         {
//             title[i] = toupper(title[i]);
//         }
//     }
//     int n = title.size();
//     int size (banner_size < 10 ? 10 : banner_size);
//     if (n > size)
//     {
//         title = title.substr(0, size - 2);
//         title[size - 4] = '.';
//         title[size - 3] = ' ';
//         n = title.size();
//     }

//     std::cout << color << std::setfill('=');
//     std::cout << std::setw(size) << "" << std::endl;
//     std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
//         << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
//         << "" << std::endl;
//     std::cout << std::setw(size) << "" << std::endl;
//     std::cout << std::setfill(' ') << RESET;
// }

// bool testDatesParsing(bool verbose = false)
// {
//     printTitle("test dates parsing");
//     std::vector<std::pair<std::string, bool> > testDates = {
//         {"002020-01-01", false},
//         {"0020-01-01", false},
//         {"20200-01-01", false},
//         {"2020 -01-01", false},
//         {"2020-01- 01", false},
//         {"2020 -01-01", false},
//         {"2020-01 -01", false},
//         {"", false},
//         {"0000-01-01", false},
//         {"1000-00-00", false},
//         {"1900-01-01", true},
//         {"1900-01-00", false},
//         {"1900-00-01", false},
//         {"1900-00", false},
//         {" 2023-04-07", false},
//         {" 2023-02-29", false},
//         {" 2023-02-28", false},
//         {"20202-02-28", false},
//         {"9999-01-01", true},
//         {"1899-01-01", false},
//         {"1900-01-01", true},
//         {"10000-01-01", false},
//         {"2020-02-29", true},
//         {"2025-01-19", true},
//         {"2025-01-39", false},
//         {"2025  -01-09", false},
//         {"2025- 01-09", false},
//         {"2025-01- 09", false},
//         {"2025-01-09 ", false},
//         {"2025 - 01 - 09", false},
//         {"0999-01-09", false},
//         {"1999-01-09", true},
//         {"-1999-01-09", false},
//         {"199:-01-09", false},
//         {"abcd-01-09", false},
//         {"2000-01-09c", false},
//         {"2020-01-32", false},
//         {"    -  -  ", false},
//         {"100090909090909090990909090909090909090990909090909090909090909090-01-01", false},
//         {"2147483650-01-01", false},
//         {"2147483648-01-01", false},
//         {"2147483647-01-01", false},
//         {"2147483646-01-01", false},
//         {"2000-10-10", true},
//     };
//     int pass = 0;

//     for (std::vector<std::pair<std::string, bool> >::const_iterator it = testDates.begin(); it != testDates.end(); ++it)
//     {
//         BitcoinExchange::Date d(it->first);
//         if (verbose)
//         {
//             std::cout << (d.good() == it->second ? GREEN "PASS" : BOLDRED "FAIL")
//                 << ": " << (it->second ? GREEN : RED) << "'" << it->first << "'\n" << RESET;
//         }
//         if (!verbose && (d.good() != it->second))
//         {
//             std::cout << BOLDRED << "'" << it->first << "' supposed to be "
//                 << (it->second ? "TRUE\n" : "FALSE\n") << RESET;
//             pass++;
//         }
//     }
//     if (!pass) std::cout << GREEN << "ALL TESTS PASSED\n" << RESET;
//     else std::cout << BOLDRED << pass << " TESTS FAILED\n" << RESET;
//     return pass;
// }

// C++11 mais on pas le droit, école de cerveaux...
// bool testDatesOperators(bool verbose = false)
// {
//     printTitle("test dates operators");
//     std::vector<std::tuple<std::string, std::string, std::string, bool>> testDates = {
//         {"2020-01-01", "2020-01-01", "==", true},
//         {"2020-01-01", "2020-02-01", "<", true},
//         {"2020-01-01", "2019-12-31", ">", true},
//         {"2020-01-01", "2020-01-01", ">=", true},
//         {"2020-01-01", "2020-02-01", "<=", true},
//         {"2023-04-07", "2023-04-07", "==", true},
//         {"2025-02-28", "2025-02-29", "<", true},
//         {"2022-12-31", "2023-01-01", "<", true},
//         {"2023-01-01", "2022-12-31", ">", true},
//         {"2025-02-29", "2025-02-28", ">", true},
//         {"1900-01-01", "1900-01-01", "==", true},
//         {"1920-01-01", "1919-12-31", ">", true},
//         {"1919-12-31", "1920-01-01", "<", true},
//         {"2000-02-29", "2000-03-01", "<", true},
//         {"2001-02-28", "2001-02-28", "==", true},
//     };

//     int pass = 0;
//     for (const auto& test : testDates)
//     {
//         BitcoinExchange::Date d1(std::get<0>(test));
//         BitcoinExchange::Date d2(std::get<1>(test));
//         std::string op = std::get<2>(test);
//         bool expected = std::get<3>(test);

//         bool result = false;
//         if (op == "==")
//             result = (d1 == d2);
//         else if (op == "<")
//             result = (d1 < d2);
//         else if (op == ">")
//             result = (d1 > d2);
//         else if (op == "<=")
//             result = (d1 <= d2);
//         else if (op == ">=")
//             result = (d1 >= d2);

//         if (verbose)
//         {
//             std::cout << ((result == expected) ? GREEN "PASS" : BOLDRED "FAIL")
//                 << ": '" << std::get<0>(test) << "' " << op << " '" << std::get<1>(test) << "' should be "
//                 << (expected ? "true" : "false") << "\n" << RESET;
//         }
//         if (result != expected)
//         {
//             std::cout << BOLDRED << "'" << it->first << "' supposed to be "
//                 << (it->second ? "TRUE\n" : "FALSE\n") << RESET;
//             pass++;
//         }
//     }
//     if (!pass) std::cout << GREEN << "ALL TESTS PASSED\n" << RESET;
//     else std::cout << BOLDRED << pass << " TESTS FAILED\n" << RESET;
//     return pass;
// }

static const BitcoinExchange::PriceHistory::File PRICE_HISTORY = "/mnt/nfs/homes/lkrief/42/cppPiscine/cpp09/ex00/samples/data.csv";

int main(int ac, char **av)
{
    if (ac == 2)
    {
        BitcoinExchange btc_ex(PRICE_HISTORY, av[1]);

        try
        {
            btc_ex.evaluate(true);
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLDRED << e.what() << '\n' << RESET;
        }
    }
    else
    {
        std::cerr << "Usage:  ./btc samples/your_sample.txt\n";
    }
}
