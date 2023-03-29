/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:03 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 05:50:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
// I reset the fill character on the last line.
// To print its value:
//   std::cout << "fill ch: '"<< std::cout.fill() << "'" << std::endl;

static void testShrubbery()
{
    printTitle("Let's plant some treeeeess");
    Bureaucrat lumberjack("LUMBERJACK", 8);
    Bureaucrat iceman("ICEMAN", 143);
    ShrubberyCreationForm shrub1("oneTree");
    ShrubberyCreationForm shrub2("twoTree");
    ShrubberyCreationForm shrub3("threeTree");

    std::cout << lumberjack << std::endl;
    std::cout << iceman << '\n' << std::endl;
    std::cout << shrub1 << std::endl;
    std::cout << shrub2 << std::endl;
    std::cout << shrub3 << '\n' << std::endl;
    try
    {
        shrub1.beSigned(lumberjack);
        shrub2.beSigned(lumberjack);
        std::cout << '\n' << shrub1 << std::endl;
        std::cout << shrub2 << std::endl;
        std::cout << shrub3 << '\n' << std::endl;
        shrub1.execute(lumberjack);
        shrub2.execute(lumberjack);
        shrub3.execute(lumberjack);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << '\n' << std::endl;
        shrub3.beSigned(iceman);
        std::cout << '\n';
        shrub3.execute(lumberjack);
        shrub2.execute(iceman);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

static void testBladeRunner()
{
    printTitle("Let's robotomizeeee");

    Bureaucrat tyrell("E. TYRELL", 1);
    Bureaucrat deckard("R. DECKARD", 42);
    Bureaucrat rachel("RACHEL", 37);
    Bureaucrat scott("R. SCOTT", 2);
    Bureaucrat littleMan("little man", 120);

    RobotomyRequestForm robotomyDeckard("R. DECKARD");
    RobotomyRequestForm robotomyDuck("paper DUCK");
    RobotomyRequestForm robotomyBoss("world's BOSS");
    RobotomyRequestForm robotomyRachel("RACHEL");

    std::cout << "\n\n          ============== CHARACTERS ============\n";
    std::cout << std::setw(12) << "" << tyrell << std::endl;
    std::cout << std::setw(12) << "" << deckard << std::endl;
    std::cout << std::setw(12) << "" << rachel << std::endl;
    std::cout << std::setw(12) << "" << scott << std::endl;
    std::cout << std::setw(12) << "" << littleMan << std::endl;
    std::cout << "          ======================================\n\n\n";

    try
    {
        robotomyDeckard.beSigned(tyrell);
        robotomyDeckard.execute(rachel);
        std::cout << '\n';
        robotomyDuck.beSigned(scott);
        robotomyDuck.execute(deckard);
        std::cout << '\n';
        robotomyBoss.beSigned(tyrell);
        robotomyBoss.execute(tyrell);
        std::cout << '\n';
        for (int i = 0; i < 40; i++)
            deckard.downGrade();
        robotomyRachel.beSigned(deckard);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << '\n' << std::endl;
        robotomyRachel.beSigned(tyrell);
        robotomyRachel.execute(deckard);
        robotomyBoss.execute(littleMan);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

static void testCoinz( int nb_tosses )
{
    printTitle("Let's tooooossss coinzzzzz");

    Bureaucrat leonard("LEONARD", 26);
    RobotomyRequestForm tossCoin("COIN");
    int total_tosses(nb_tosses);
    int total_heads(0);

    tossCoin.beSigned(leonard);
    for (int i = 0; i < nb_tosses; i++)
    {
        if (tossCoin.execute(leonard))
            total_heads++;
    }

    std::cout
        << "\n      Total tosses: " << total_tosses
        << "\n      Total heads:  " << total_heads
        << "\n      Probability:  " << static_cast<float>(total_heads) / static_cast<float>(total_tosses)
        << std::endl;
}

static void testPardons()
{
    printTitle("Pardonnons les navets...", false);

    Bureaucrat leonard("LEONARD", 4);
    PresidentialPardonForm funnygames("Funny Games");
    PresidentialPardonForm billboards("100 Billboards");
    PresidentialPardonForm waltermitty("The Secret Life of Walter Mitty");
    PresidentialPardonForm aboutdesouffle("A bout de souffle");

    try
    {
        std::cout << "\n";
        billboards.beSigned(leonard);
        billboards.execute(leonard);
        funnygames.beSigned(leonard);
        funnygames.execute(leonard);
        aboutdesouffle.beSigned(leonard);
        aboutdesouffle.execute(leonard);
        waltermitty.beSigned(leonard);
        waltermitty.execute(leonard);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }
}

int main(void)
{
    srand(time(NULL) + getpid());

    // ShrubberyCreationForm
        testShrubbery();

    // RobotomyRequestForm
        testBladeRunner();
        if (false)
        {
            testCoinz(100);
        }

    // PresidentialPardonForm
        testPardons();

    std::cout << std::endl;
    return (0);
}