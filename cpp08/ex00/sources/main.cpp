/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/20 19:18:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

const unsigned int BANNER_SIZE = 55;

static void printTitle(std::string title, bool toUpper = true, int banner_size = BANNER_SIZE)
{
    static int first;
    if (first > 0)
        std::cout << std::endl;
    else
        first++;

    title = " " + title + " ";
    if (toUpper)
    {
        for (int i = 0; title[i]; i++)
        {
            title[i] = toupper(title[i]);
        }
    }
    int n = title.size();
    int size (banner_size < 10 ? 10 : banner_size);
    if (n > size)
    {
        title = title.substr(0, size - 2);
        title[size - 4] = '.';
        title[size - 3] = ' ';
        n = title.size();
    }

    std::cout << std::setfill('=');
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void vectorUnitTest()
{
    static int N = 0;

    std::stringstream ss;
    ss << N;
    std::string title = "vector unit test " + ss.str();
    printTitle(title);
    std::list<int> s = {20,3,2,1,2,3,1,2};
    // printVector(s);
    easyfind(s, 1);
    N++;
}

int main()
{
    vectorUnitTest();
    vectorUnitTest();
    vectorUnitTest();
    vectorUnitTest();
}
