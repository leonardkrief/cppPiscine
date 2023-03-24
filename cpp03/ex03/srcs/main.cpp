/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 06:13:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <iomanip>
#define SIZE 52

int	main(void)
{
    {
        DiamondTrap dd("gi");
        dd.whoAmI();
    }
    std::cout << std::endl << std::endl;
    {
        DiamondTrap rien("dsv");
        DiamondTrap r("23332");

        r.whoAmI();
        r.print();
        r = rien;
        r.whoAmI();
        r.print();
    }
}