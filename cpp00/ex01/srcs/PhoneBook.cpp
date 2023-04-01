/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 18:23:04 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>


PhoneBook::PhoneBook(): _size(0)
{
	std::cout << "[" << (void*)this << "] Phonebook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "[" << (void*)this << "] Phonebook destructor called" << std::endl;
}

std::string	PhoneBook::welcome(void) const
{
	std::string	input;
	std::cout << "==========================================================" << std::endl;
	std::cout << "'ADD'       add a contact" << std::endl;
	std::cout << "'SEARCH'    search for a contact" << std::endl;
	std::cout << "'EXIT'      quit the program" << std::endl;
	std::cout << std::endl << std::flush;
	std::cout << ">> " << std::flush;
	if (!std::getline(std::cin, input))
		exit(0);
	return input; ;
}

void	PhoneBook::previewContacts(void) const
{
    std::cout << "==========>> CONTACTS <<==========\n";
	for (int i = 0; i < this->_size; i++)
		this->_contacts[i].preview(i + 1);
}

void	PhoneBook::searchEntry(void) const
{
	int		input = -1;
	bool	valid = false;

	if (this->_size == 0)
    {
		std::cout << "No contacts to display" << std::endl << std::flush;
		return ;
	}
	while (!valid)
    {
		input = 0;
		this->previewContacts();
        std::cout << "Enter the contact number you want to display: " << std::flush;
		std::cin >> input;
		if (std::cin.eof())
        {
			exit(0);
        }
		try
		{
			if (std::cin.good() && (input > 0 && input <= this->_size))
			{
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				this->_contacts[input - 1].print(input);
				valid = true;
			}
			else
			{
				throw std::invalid_argument("Please enter an existing contact number.\n");
			}
		}
		catch (const std::invalid_argument& e)
		{
				std::cout << "Invalid input: " << e.what() << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::addEntry(void)
{
	static int entry = 0;

	if (entry == 8)
		entry = 0;
	this->_contacts[entry].init();
	if (this->_size < 8)
		this->_size++;
	entry++;
}