/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 13:54:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>


int	main(void)
{
    std::cout << "=================== WEAPON TEST ===================" << std::endl;
    {
        Weapon weapon("Big Club");

        std::cout << "New weapon is a " << weapon.getType() << std::endl;
        weapon.setType("Giant Leg");
        std::cout << "Weapon is now a " << weapon.getType() << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << "=================== HUMAN_A TEST ==================" << std::endl;
        Weapon weaponA("Shark Tooth");
        HumanA humA("Bobby", weaponA);

        humA.attack();
    }
    {
        std::cout << std::endl;
        std::cout << "=================== HUMAN_B TEST ==================" << std::endl;
        HumanB humB("Naked Man");

        humB.attack();
        Weapon weaponB("Fat Axe");
        humB.setWeapon(weaponB);
        humB.attack();
    }
    return 0;
}
