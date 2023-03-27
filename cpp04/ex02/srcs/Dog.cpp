/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:37:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "[" << (void *)this
        << "] 'Dog' default constructor" << std::endl;
}

Dog::Dog( const Dog& dog ) : Animal(dog), _brain(new Brain(*(dog._brain)))
{
    std::cout << "[" << (void *)this
        << "] 'Dog' copy constructor" << std::endl;
}


Dog::~Dog()
{
    std::cout << "[" << (void *)this
        << "] 'Dog' destructor" << std::endl;
    delete _brain;
}

Dog& Dog::operator=( const Dog& dog )
{
    if (this != &dog)
    {
        this->_type = dog._type;
        *(this->_brain) = *(dog._brain);
    }
    return *this;
}

void Dog::printIdeas( int i, int j ) const
{
    std::cout << "Dog ideas:    ";
    this->_brain->printIdeas(i, j);
}

void Dog::makeSound() const
{
    std::cout << "Dog:\n  grr... bark... bark... BARKSSSSSS !!!!"
        << std::endl;
}
