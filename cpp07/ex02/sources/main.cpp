/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/08 00:53:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"
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
    int n(std::rand());
    int d(std::rand());
    return static_cast<float>(d == 0 ? n : static_cast<float>(n) / static_cast<float>(d));
}

template <>
double getValue<double>()
{
    int n(std::rand());
    int d(std::rand());
    return static_cast<double>(d == 0 ? n : static_cast<double>(n) / static_cast<double>(d));
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

template<typename T>
void randomArray(Array<T>& tab)
{
    for (unsigned int i = 0; i < N; i++)
        tab[i] = getValue<T>();
}

template<typename T>
int testArray(Array<T> elem)
{
    printTitle("test " + std::string(typeid(T).name()));

    std::cout << "OG        " << elem << std::endl;

    randomArray<T>(elem);
    Array<T> tab(elem);

    std::cout << "RANDOM    " << elem << std::endl;
    std::cout << "COPY      " << tab << std::endl;
    try { tab[N + 1] = 0; }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    return 0;
}

int main()
{
    std::srand(std::time(0));

    testArray(Array<char>(N));
    testArray(Array<int>(N));
    testArray(Array<float>(N));
    testArray(Array<double>(N));
}
