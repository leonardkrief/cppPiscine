/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/15 16:04:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact created " << (void*)this << std::endl << std::flush;
}

Contact::~Contact()
{
	std::cout << "Contact destroyed " << (void*)this << std::endl << std::flush;
}

void	Contact::init(void)
{
	// std::cin.ignore();
	this->_first_name = _getInput("First name: ");
	this->_last_name = _getInput("Last name: ");
	this->_nickname = _getInput("Nickname: ");
	this->_phone_number = _getInput("Phone number: ");
	this->_darkest_secret = _getInput("Darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::_getInput(std::string str) const
{
	std::string	input = "";
	bool		valid = false;

	while (!valid) {
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && input.length())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input. Please try again: " << std::endl;
		}
	}
	return (input);
}

std::string Contact::_printLen(std::string str) const {
	if (str.length() > 10)
	return str.substr(0, 9) + ".";
	return str;
}

void	Contact::setIndex(int i) {
	this->_index = i;
}

void	Contact::preview(int index) const {
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_first_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_last_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::print(int index) const {
	if (this->_first_name.empty() || this->_last_name.empty() || this->_nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
	std::cout << "First name:\t" << this->_first_name << std::endl;
	std::cout << "Last name:\t" << this->_last_name << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone number:\t" << this->_phone_number << std::endl;
	std::cout << std::endl;
}
