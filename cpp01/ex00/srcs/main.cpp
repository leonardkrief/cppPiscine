/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 02:46:25 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "============= stackZombies =============" << std::endl;
	Zombie	zombie1("Bertrand");
	Zombie	zombie2("Francis");
	Zombie	zombie3("Samantha");
	Zombie	zombie4;
	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	zombie4.announce();
	randomChump("randomChumpZ");
	std::cout << std::endl;

	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZombie;
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete(heapZombie);
}
