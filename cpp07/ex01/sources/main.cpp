/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/07 19:24:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

const unsigned int BANNER_SIZE = 55;
const unsigned int N = 5;

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

template <typename T>
T getValue()
{
    throw std::runtime_error("Bad request");
}

template <>
char getValue<char>()
{
    return static_cast<char>(33 + (std::rand() % (127 - 34)));
}

template <>
int getValue<int>()
{
    return std::rand();
}

template <>
float getValue<float>()
{
    int n(static_cast<float>(std::rand()));
    int d(static_cast<float>(std::rand()));
    return static_cast<float>(n / d == 0 ? 1 : d);
}

template <>
double getValue<double>()
{
    int n(static_cast<double>(std::rand()));
    int d(static_cast<double>(std::rand()));
    return static_cast<double>(n / d == 0 ? 1 : d);
}

template <>
std::string getValue<std::string>()
{
    int len = 4;
    char s[len];

    for (int i = 0; i < len; i++)
        s[i] = static_cast<char>(97 + (std::rand() % 26));
    return std::string(s);
}

void plus1(int& n)
{
    n++;
}
int testPlus1()
{
    int tab[N] = {getValue<int>() % 100, getValue<int>() % 100, getValue<int>() % 100, getValue<int>() % 100, getValue<int>() % 100};

    printTitle("test +1");
    std::cout << "BEFORE  ";
    printTab(tab);
    iter(tab, N, plus1);
    std::cout << "AFTER   ";
    printTab(tab);
    return 0;
}

void toUpper(std::string& str)
{
    for (unsigned int i = 0; i < str.size(); i++)
        str[i] = std::toupper(str[i]);
}

int testToUpper()
{
    std::string s[N] = {getValue<std::string>(), getValue<std::string>(), getValue<std::string>(), getValue<std::string>(), getValue<std::string>()};

    printTitle("to upper");
    std::cout << "BEFORE  ";
    printTab(s);
    iter(s, N, toUpper);
    std::cout << "AFTER   ";
    printTab(s);
    return 0;
}


void shiftBits(int& n)
{
    n <<= 1;
}

int testShiftBits()
{
    int tab[N] = {getValue<int>() % 100 - 50, getValue<int>() % 100 - 50, getValue<int>() % 100 - 50, getValue<int>() % 100 - 50, getValue<int>() % 100 - 50};

    printTitle("shift bits (mult by 2)");
    std::cout << "BEFORE  ";
    printTab(tab);
    iter(tab, N, shiftBits);
    std::cout << "AFTER   ";
    printTab(tab);
    return 0;
}

int main()
{
    std::srand(std::time(0));
    testPlus1();
    testToUpper();
    testShiftBits();
}
