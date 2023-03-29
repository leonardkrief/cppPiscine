/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:03 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 07:03:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>

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

// One way to avoid the "chained" deletes would be to use smart pointers:
//      std::unique_ptr<AForm> form1(intrn.makeForm(
//                                   "shrubbery creation", "Corrector"));
static void testIntern()
{
    printTitle("Let's use the interns");
    Intern intrn;
    try
    {
        AForm* form1 = intrn.makeForm("shrubbery creation", "Corrector");
        delete form1;
        AForm* form2 = intrn.makeForm("robotomy request", "Corrector");
        delete form2;
        AForm* form3 = intrn.makeForm("presidential pardon", "Corrector");
        delete form3;
        AForm* form4 = intrn.makeForm("target = loser", "Leonard");
        delete form4;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    testIntern();
    std::cout << std::endl;
    return (0);
}