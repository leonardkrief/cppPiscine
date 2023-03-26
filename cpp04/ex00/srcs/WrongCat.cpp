/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:22:18 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[" << (void *)this
        << "] 'WrongCat' default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[" << (void *)this
        << "] 'WrongCat' destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat:\n  grr... miaou... Miaou... MIAOUUUUUU... !!!!"
        << std::endl;
}