/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 01:30:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> messages = {
	"landed on earth",
	"jumped out the grave",
	"ate a bug as he woke up",
	"is looking through his hands",
	"woke up",
	"is looking for new brains to eat",
	"wanted to start a new busines but remembered in time he was a zombie",
	"is chilling like a vilain",
	"looks fresh",
	"says wassup",
	"woke up with a DJ Khaled rant playing and is now a happy zombie",
	"is looking for Brother Mouzone",
	"says that Omar says hello"
};

int i = 1;
int r = 4;

Zombie::Zombie()
{

	this->_name = "Zombie";
	std::cout << this->_name << " " <<
		messages[(r * i * (1 - i)) % messages.size()] << std::endl;
	i++;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << this->_name << " " <<
		messages[(r * i * (1 - i)) % messages.size()] << std::endl;
	i++;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}