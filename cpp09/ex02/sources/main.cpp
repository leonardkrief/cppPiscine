/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/26 01:03:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

const unsigned int BANNER_SIZE = 55;

static void printTitle(std::string title, std::string color = BOLDYELLOW, bool toUpper = true, int banner_size = BANNER_SIZE)
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

    std::cout << color << std::setfill('=');
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ') << RESET;
}

double unitTestVector(Pmerge& m)
{
    clock_t start = clock();
    std::vector<int> v = m.vectorSort();
    clock_t end = clock();

    return (end - start) / static_cast<double>CLOCKS_PER_SEC;
}

double unitTestDeque(Pmerge& m)
{
    clock_t start = clock();
    std::deque<int> v = m.dequeSort();
    clock_t end = clock();

    return (end - start) / static_cast<double>CLOCKS_PER_SEC;
}

void unitTest(Pmerge& m, const bool& debug = false, std::string container = "", const bool& clockBool = true)
{
    m.setDebug(debug);
    if (container == "vector") unitTestVector(m);
    else if (container == "deque")  unitTestDeque(m);
    else
    {
        std::cout << "Before: " << m.getInput() << std::endl;
        double vtime = unitTestVector(m);
        double dtime = unitTestDeque(m);
        std::cout << "After: " << m.getSorted() << std::endl;
        if (clockBool)
        {
            std::cout << "Time to process a range of " << m.getNbElements() << " elements with std::vector<int> : " << vtime << " us" << std::endl;
            std::cout << "Time to process a range of " << m.getNbElements() << " elements with std::deque<int> : " << dtime << " us" << std::endl;
        }
    }
}

void tests(Pmerge& m, bool debug = false)
{
    printTitle("bunch of tests");
    unitTest(m, debug);
}

int main(int ac, char**av)
{
    std::string str;
    for (int i = 1; i < ac; i++)
    {
        str.append(av[i]);
        str.append(" ");
    }

    try
    {
        std::string input(str);
        Pmerge m(input);
        tests(m, false);
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLDRED << e.what() << std::endl << RESET;
    }

    return (0);
}