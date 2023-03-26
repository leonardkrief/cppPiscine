/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:29:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

static void defaultPointerTest()
{
    printTitle("default pointer test");
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
}

static void defaultReferenceTest()
{
    printTitle("default reference test");
    const Animal& meta = Animal();
    const Animal& j = Dog();
    const Animal& i = Cat();
    std::cout << j.getType() << " " << std::endl;
    std::cout << i.getType() << " " << std::endl;
    i.makeSound(); //will output the cat sound!
    j.makeSound();
    meta.makeSound();
}

static void wrongAnimalPointerTest()
{
    printTitle("wrong animal pointer test");
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    meta->makeSound();
    delete i;
    delete meta;
}

static void wrongAnimalReferenceTest()
{
    printTitle("wrong animal reference test");
    const WrongAnimal& meta = WrongAnimal();
    const WrongAnimal& i = WrongCat();
    std::cout << i.getType() << " " << std::endl;
    i.makeSound(); //will output the cat sound!
    meta.makeSound();
}


int main()
{
    defaultPointerTest();
    defaultReferenceTest();
    wrongAnimalPointerTest();
    wrongAnimalReferenceTest();
    return 0;
}