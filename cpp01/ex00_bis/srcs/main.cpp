/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 01:26:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "============= stackZombies =============" << std::endl;
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");
	Zombie	zombie3;
	Zombie	zombie4;
	Zombie	zombie5;
	Zombie	zombie6;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChumpZ");

	std::cout << std::endl;
	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("HeapZ");
	heapZ->announce();
	delete(heapZ);

	return (0);
}
