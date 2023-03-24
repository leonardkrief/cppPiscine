/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 03:36:54 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>
#define SIZE 52

int	main(void)
{
	FragTrap	fragTrap("Fraggy");
	FragTrap	f2("Ziggy");
	
	fragTrap.attack("random alien");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(50);
	fragTrap.beRepaired(30);
    f2 = fragTrap;
	fragTrap.print();
    f2.print();
	fragTrap.takeDamage(100);
	fragTrap.print();
	return (0);
}