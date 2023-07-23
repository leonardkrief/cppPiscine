/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/23 19:26:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <iostream>
#include <iomanip>

// const unsigned int BANNER_SIZE = 55;

// static void printTitle(std::string title, bool toUpper = true, int banner_size = BANNER_SIZE)
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

//     std::cout << std::setfill('=');
//     std::cout << std::setw(size) << "" << std::endl;
//     std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
//         << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
//         << "" << std::endl;
//     std::cout << std::setw(size) << "" << std::endl;
//     std::cout << std::setfill(' ');
// }

int main(int ac, char **av)
{
    std::string str = "1 2 * 2 / 2 * 2 4 - +", opt;
    bool debug = false;

    try
    {
        if (ac == 2) str = av[1];
        else if (ac == 3)
        {
            opt = av[1];
            str = av[2];
            if (opt == "-d" || opt == "--debug") debug = true;
            else if (str == "-d" || str == "--debug")
            {
                debug = true;
                std::swap(opt, str);
            }
            else throw std::runtime_error("./rpn [-d, --debug] expression");
        }
        else throw std::runtime_error("./rpn [-d, --debug] expression");
        RPN test(str);
        std::cout << test.getRPN(debug) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLDRED << e.what() << '\n' << RESET;
    }
}
