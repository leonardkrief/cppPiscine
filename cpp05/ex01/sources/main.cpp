/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:03 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/28 02:08:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}
// I reset the fill character on the last line.
// To print its value:
//   std::cout << "fill ch: '"<< std::cout.fill() << "'" << std::endl;

void testBugatti(void)
{
    printTitle("I WANT MY BUGATTI");
    Bureaucrat turtle("TURTLE", 8);
    Form form("buy a Bugatti", 5, 15);

    std::cout << turtle << std::endl;
    std::cout << form << std::endl;
    try
    {
        form.beSigned(turtle);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    turtle.upGrade();
    turtle.upGrade();
    turtle.upGrade();
    std::cout << turtle << std::endl;
    form.beSigned(turtle);
    std::cout << form << std::endl;
}

void testConstructorsHigh(void)
{
    printTitle("Constructors high level test");
    try
    {
        Form form("fly to another galaxy", 0, 0);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("fly to another galaxy", 1, 0);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("fly to another galaxy", 0, 1);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("fly to another galaxy", 1, 1);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testConstructorsLow(void)
{
    printTitle("Constructors low level test");
    try
    {
        Form form("laugh to my jokes", 151, 151);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("laugh to my jokes", 150, 151);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("laugh to my jokes", 151, 150);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Form form("laugh to my jokes", 150, 150);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testConstructorsRandom(void)
{
    printTitle("Constructors random tests");
    try
    {
        Bureaucrat bigman("Big Man", 3);
        Form form("get a UV session", 120, 145);
        Form formal("director's board meeting", 10, 19);
        Form test(formal);
        std::cout << form << std::endl;
        std::cout << test << std::endl;
        formal.beSigned(bigman);
        form = formal;
        std::cout << std::endl;
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    testBugatti();
    testConstructorsHigh();
    testConstructorsLow();
    testConstructorsRandom();
    std::cout << std::endl;
    return (0);
}