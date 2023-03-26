/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:43:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Animal.hpp"
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


static void	testLeaks(void)
{
	printTitle("LEAKS");
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	delete dog;
	delete cat;
}

static void	testDeepCopy(void)
{
    printTitle("DEEP COPY");
    {
        Dog	dog1;
        Dog	dog2;

        dog1.printIdeas();
        dog2.printIdeas();

        dog2 = dog1;
        std::cout << "After assignation :" << std::endl;
        dog1.printIdeas();
        dog2.printIdeas();
    }
    std::cout << std::endl << std::endl;
    {
        Cat cat1;
        Cat cat2(cat1);

        cat1.printIdeas();
        cat2.printIdeas();
    }
}

static void	testSubject(int size)
{
	printTitle("SUBJECT");
	Animal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}

	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}

int main()
{
    testLeaks();
    testDeepCopy();
    testSubject(3);
    return 0;
}
