/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:10:43 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/17 15:29:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac <= 1) {
		harl.complain("");
		return -1;
	}
	for (int i = 1; i < ac; ++i)
	{
		harl.complain(av[i]);
	}
	return 0;
}