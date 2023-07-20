/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/20 23:18:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include <list>
#include <deque>
#include <array>

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

const unsigned int NB_CONTAINERS = 3;

void printUnitTestTitle( int c )
{
    static int N = 1;
    const char* containers[NB_CONTAINERS] = {
        "vector",
        "list",
        "deque",
    };
    std::stringstream ss;
    ss << N;
    std::string title = "unit test " + ss.str() + ": " + containers[c];
    printTitle(title);
    N++;
}

void unitTest()
{
    try
    {
        int c = rand() % NB_CONTAINERS;
        printUnitTestTitle(c);
        switch (c)
        {
            case 0:
            {
                std::vector<int> myContainer = randomContainerOfInts<std::vector>();
                std::cout << myContainer << std::endl;
                easyfind(myContainer, rand() % 20);
                break;
            }
            case 1:
            {
                std::list<int> myContainer = randomContainerOfInts<std::list>();
                std::cout << myContainer << std::endl;
                easyfind(myContainer, rand() % 20);
                break;
            }
            case 2:
            {
                std::deque<int> myContainer = randomContainerOfInts<std::deque>();
                std::cout << myContainer << std::endl;
                easyfind(myContainer, rand() % 20);
                break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int ac, char **av)
{
    srand(time(0));
    if (ac == 2)
    {
        int n = atoi(av[1]);
        for (int i = 0; i < n; i++)
        {
            unitTest();
        }
    }
    else
    {
        unitTest();
    }
}
