// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Brain.cpp                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/24 16:52:05 by lkrief            #+#    #+#             */
// /*   Updated: 2023/03/27 00:00:39 by lkrief           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <iomanip>

static std::string	randomString(int size)
{
	const std::string	alphaNum = "abcdefghijklmnopqrstuvwxyz0123456789?!&";
	std::string			randomStr = "";

	for (int i = 0; i < size; i++)
		randomStr += alphaNum[std::rand() % alphaNum.size()];
	return (randomStr);
}

Brain::Brain()
{
    std::cout << "[" << (void *)this
        << "] 'Brain' default constructor" << std::endl;
    for (int i = 0; i < 100; i++)
		_ideas[i] = randomString(4);
}

Brain::Brain( const Brain& brain )
{
    std::cout << "[" << (void *)this
        << "] 'Brain' copy constructor" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "[" << (void *)this
        << "] 'Brain' destructor" << std::endl;
}

Brain& Brain::operator=( const Brain &brain )
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = brain._ideas[i];
        }
    }
    return *this;
}

void Brain::printIdea( int i ) const
{
    static int n;

    if (i >= 0 && i < 100 && _ideas[i].size() > 0)
    {
        std::cout << i << "[" << _ideas[i] << "]";
        if (n % 5 != 4)
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << std::endl;
        }
        n++;
    }
}

void Brain::printIdeas( int i, int j ) const
{
    for (int n = i; n < j; n++)
    {
        printIdea(n);
    }
}
