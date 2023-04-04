/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 12:36:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string horde_name_1 = "Bernhardt";
	std::string horde_name_2 = "Sophie";
	std::string horde_name_3 = "Isabelle";

	Zombie*	horde_1 = zombieHorde(2, horde_name_1);
	Zombie*	horde_2 = zombieHorde(3, horde_name_2);
	Zombie*	horde_3 = zombieHorde(5, horde_name_3);
	
	announceHorde(2, horde_1);
	announceHorde(3, horde_2);
	announceHorde(5, horde_3);

	delete[] horde_1;
	delete[] horde_2;
	delete[] horde_3;
}
