/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:03 by lkrief            #+#    #+#             */
/*   Updated: 2023/06/22 14:46:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <iomanip>

#define BANNER_SIZE 60

static void printTitle(std::string title, bool toUpper = true)
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
    int size (BANNER_SIZE < 10 ? 10 : BANNER_SIZE);
    if (n > size)
    {
        title = title.substr(0, size - 2);
        title[size - 4] = '.';
        title[size - 3] = ' ';
        n = title.size();
    }

    std::cout << std::setfill('=');
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}
// I reset the fill character on the last line.
// To print its value:
//   std::cout << "fill ch: '"<< std::cout.fill() << "'" << std::endl;

void testBasic(void)
{
    printTitle("Basic test");
    try
    {
        Bureaucrat bob("bob", 6);

        std::cout << bob << std::endl;
        bob.downGrade();
        std::cout << bob << std::endl;
        bob.upGrade();
        bob.upGrade();
        bob.upGrade();
        bob.upGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testExceptionLow(void)
{
    printTitle("Exception low test");
    try
    {
        Bureaucrat bob("bob", 151);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testExceptionHigh(void)
{
    printTitle("Exception high test");
    try
    {
        Bureaucrat bob("bob", 0);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testDownGrade(void)
{
    printTitle("Exception downgrade test");
    try
    {
        Bureaucrat bob("bob", 2);
        bob.upGrade();
        std::cout << bob << std::endl;
        bob.upGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testUpGrade(void)
{
    printTitle("Exception upgrade test");
    try
    {
        Bureaucrat bob("bob", 149);
        bob.downGrade();
        std::cout << bob << std::endl;
        bob.downGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testOCN(void)
{
    printTitle("Orthodox canonical form test");
    try
    {
        Bureaucrat bob("bob", 149);
        Bureaucrat ava = bob;
        std::cout << bob << std::endl;
        std::cout << ava << std::endl;
        std::cout << "_name member is const so I cannot initialize\
it inside a copy constructor" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    testBasic();
    testExceptionLow();
    testExceptionHigh();s
    testDownGrade();
    testUpGrade();
    testOCN();
    std::cout << std::endl;
    return (0);
}