/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 07:21:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
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

static void testSubject(void)
{
	printTitle("SUBJECT");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void	testCharacter(void)
{
	printTitle("CHARACTER");
	ICharacter	*hero = new Character("Leonard");
	ICharacter	*enemy = new Character("Correcteur");
	AMateria	*ice = new Ice();

	hero->equip(new Ice());
	hero->equip(ice);
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Ice());
	enemy->equip(new Cure());
	enemy->equip(new Cure());
	enemy->equip(new Cure());

	hero->printInventory();
	enemy->printInventory();

	hero->use(0, *enemy);
	hero->use(1, *enemy);
	hero->use(3, *enemy);
	enemy->use(2, *hero);

	hero->unequip(1);
	hero->printInventory();
	hero->use(1, *enemy);

	hero->equip(new Cure());
	hero->printInventory();
	hero->use(1, *enemy);

	delete hero;
	delete enemy;
	delete ice;
}

static void	testMateriaSource()
{
	printTitle("MATERIA SOURCE");
	IMateriaSource	*matSource = new MateriaSource();
	ICharacter		*hero = new Character("Leonard");
	ICharacter		*enemy = new Character("Correcteur");
	
	matSource->learnMateria(new Ice());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());

	hero->printInventory();
	hero->equip(matSource->createMateria("ice"));
	hero->equip(matSource->createMateria("cure"));
	hero->equip(matSource->createMateria("cure"));
	hero->equip(matSource->createMateria("ice"));
	hero->printInventory();
	hero->equip(matSource->createMateria("cure"));
	hero->printInventory();

	hero->use(0, *enemy);
	hero->use(2, *enemy);

	delete matSource;
	delete hero;
	delete enemy;
}

int	main(void)
{
	testSubject();
	testCharacter();
	testMateriaSource();
	return (0);
}