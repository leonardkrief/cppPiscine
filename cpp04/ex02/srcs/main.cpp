/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:54:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

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

static void	testSubject()
{
    printTitle("SUBJECT");
    Animal animal;
    AAnimal aanimal;
}

int main()
{
    testSubject();
    return 0;
}
