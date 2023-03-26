/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 16:59:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "[" << (void *)this
        << "] 'Dog' default constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[" << (void *)this
        << "] 'Dog' destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog:\n  grr... bark... bark... BARKSSSSSS !!!!"
        << std::endl;
}