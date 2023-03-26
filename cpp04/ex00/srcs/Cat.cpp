/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:18:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "[" << (void *)this
        << "] 'Cat' default constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[" << (void *)this
        << "] 'Cat' destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat:\n  grr... miaou... Miaou... MIAOUUUUUU... !!!!"
        << std::endl;
}
