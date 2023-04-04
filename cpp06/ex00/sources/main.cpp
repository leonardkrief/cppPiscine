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
#include <sstream>
#include <locale>

int main(int ac, char** av)
{
    std::locale::global(std::locale(""));
    int x = 1;
    if (ac == 1)
    {
        std::cout << "No input provided. Abort...\n";
        exit(EXIT_FAILURE);
    }
    if (std::string(av[1]) == "-v")
    {
        ScalarConverter::verboseModeON();
        x++;
    }
    for (int i = x; i < ac; i++)
    {
        try
        {
            ScalarConverter::convert(av[i]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}