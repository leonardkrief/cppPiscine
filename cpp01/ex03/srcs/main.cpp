/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 19:36:27 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>


int	main(void)
{
	std::cout << "-------------------WEAPON TEST-------------------" << std::endl;
	{
		Weapon weapon("Big Club");

		weapon.whatType();
		weapon.setType("Giant Leg");
		weapon.whatType();
	}
	std::cout << std::endl;
	std::cout << "-------------------HUMAN_A TEST------------------" << std::endl;
	{
		Weapon weaponA("Shark Tooth");
		HumanA humA("Bobby", weaponA);

		humA.attack();
	}
	std::cout << std::endl;
	std::cout << "-------------------HUMAN_B TEST------------------" << std::endl;
	{
		Weapon weaponB("Fat Axe");
		HumanB humB("Naked Man");

		humB.attack();
		humB.setWeapon(weaponB);
		humB.attack();
	}
}
