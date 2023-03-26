// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Cat.cpp                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
// /*   Updated: 2023/03/26 23:42:07 by lkrief           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "[" << (void *)this
        << "] 'Cat' default constructor" << std::endl;
}

Cat::Cat( const Cat& cat ) : Animal(cat), _brain(new Brain(*(cat._brain)))
{
    std::cout << "[" << (void *)this
        << "] 'Cat' copy constructor" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "[" << (void *)this
        << "] 'Cat' destructor" << std::endl;
}

Cat& Cat::operator=( const Cat& cat )
{
    if (this != &cat)
    {
        this->_type = cat._type;
        *(this->_brain) = *(cat._brain);
    }
    return *this;
}

void Cat::printIdeas( int i, int j ) const
{
    std::cout << "Cat ideas:    ";
    this->_brain->printIdeas(i, j);
}

void Cat::makeSound() const
{
    std::cout << "Cat:    grr... miaou... Miaou... MIAOUUUUUU... !!!!"
        << std::endl;
}
