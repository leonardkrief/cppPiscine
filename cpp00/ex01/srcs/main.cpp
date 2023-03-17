/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/14 19:09:08 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input = "";

	std::cout << std::endl << std::flush;
	while (true)
	{
		input = phonebook.welcome();
		if (input == "ADD")
			phonebook.addEntry();
		else if (input == "SEARCH")
			phonebook.searchEntry();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid input, please enter a valid input" << std::endl << std::flush;
	}
	return (0);
}
