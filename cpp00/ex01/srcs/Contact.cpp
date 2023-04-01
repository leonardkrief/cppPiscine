/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 18:18:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <limits>
#include <stdio.h>

Contact::Contact()
{
	std::cout << "[" << (void*)this << "] Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "[" << (void*)this << "] Contact destructor called" << std::endl;
}

void	Contact::init(void)
{
	this->_first_name = _getInput("First name: ");
	this->_last_name = _getInput("Last name: ");
	this->_nickname = _getInput("Nickname: ");
	this->_phone_number = _getInput("Phone number: ");
	this->_darkest_secret = _getInput("Darkest secret: ");
	std::cout << std::endl;
}

// when we press CTRL+D after a getline occured, the eof flag is set
// and depending on the platform and implementation of c++ standard library,
// the stdin stream buffer is closed
// Hence, just calling std::cin.clear() is not enough to reset the eof flag and the sdin buffer
// I had to call clearerr(stdin) in addition to clear to reset the eof flag and ignore any remaining input in the buffer
std::string Contact::_getInput(std::string str) const
{
	std::string	input = "";
	bool		valid = false;

	while (!valid)
	{
	    std::cout << str << std::flush;
		
		if (!std::getline(std::cin, input))
		{
			exit (0);
		}
        else if (input.empty())
        {
            std::cout << "Input cannot be empty" << std::endl;
            continue ;
        }
        valid = true;
	}
	return (input);
}

std::string Contact::_printLen(std::string str) const {
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	return str;
}

void	Contact::setIndex(int i)
{
	this->_index = i;
}

static void	previewOne( const std::string str )
{
    int len = str.length();
    std::cout << std::setw(5) << std::right << str.substr(0, len / 2);
    std::cout << std::setw(5) << std::left << str.substr(len / 2) << "|";
}

void	Contact::preview(int index) const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
		return ;
	std::cout << " #" << index << " |";
	previewOne(this->_printLen(this->_first_name));
	previewOne(this->_printLen(this->_last_name));
	previewOne(this->_printLen(this->_nickname));
	std::cout << std::endl;
}

void	Contact::print(int index) const
{
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
		return ;
	std::cout << "\n";
	std::cout << "====>> CONTACT #" << index << " <<====\n";
	std::cout << "First name:\t" << this->_first_name << "\n";
	std::cout << "Last name:\t" << this->_last_name << "\n";
	std::cout << "Nickname:\t" << this->_nickname << "\n";
	std::cout << "Phone number:\t" << this->_phone_number << "\n";
	std::cout << std::endl;
}
