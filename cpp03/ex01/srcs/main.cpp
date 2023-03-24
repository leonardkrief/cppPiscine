/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 04:32:32 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <iomanip>

#include "ScavTrap.hpp"
#define SIZE 52

static void printTitle(std::string title, bool toUpper = true)
{
    static int first;
    std::string toPrint;
    unsigned int size = (SIZE > 10 ? SIZE : 10);
    char c = '=';
    unsigned int n;

    if (first > 0)
        std::cout << std::endl;
    else
        first++;

    toPrint = " " + title + " ";
    if (toUpper)
    {
        for (int i = 0; toPrint[i]; i++)
            toPrint[i] = toupper(toPrint[i]);
    }
    n = toPrint.size();
    if (n > size)
    {
        toPrint = toPrint.substr(0, size - 2);
        toPrint[size - 4] = '.';
        toPrint[size - 3] = ' ';
        n = toPrint.size();
    }
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
    std::cout << toPrint.substr(n / 2, n - n / 2);
    std::cout << std::setfill(c) << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

int main(void)
{
    {
        printTitle("testing member functions");
        ClapTrap clapTrap("Clappy");
        ScavTrap scavTrap("Scavvy");
        
        scavTrap.attack("random human");
        clapTrap.attack("random human");
        scavTrap.guardGate();
        scavTrap.takeDamage(30);
        scavTrap.beRepaired(10);
        scavTrap.takeDamage(50);
        scavTrap.takeDamage(30);
        scavTrap.takeDamage(10);
        scavTrap.beRepaired(1);
        scavTrap.attack("Clappy");
    }
    {
        printTitle("VIRTUAL TEST");
        ScavTrap scavTrap("Scavvy");
        ClapTrap clapTrap("Clappy");
        ClapTrap* ctPtr = &scavTrap;

        ctPtr->attack("clTrp ptr");
        scavTrap.attack("scavTrap ");
        clapTrap.attack("clapTrap ");
    }
    {
        printTitle("running out of energy");
        ScavTrap scavTrap("Scavvy");

        for (int i = 0; i < 50; i++)
            scavTrap.attack("random human");
        scavTrap.beRepaired(10);
        scavTrap.attack("random human");
        scavTrap.takeDamage(100);
        scavTrap.print();

    }
    return (0);
}