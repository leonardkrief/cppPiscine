/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 12:38:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string     : " << (void *) &str << std::endl;
	std::cout << "stringPTR  : " << (void *) stringPTR << std::endl;
	std::cout << "stringREF  : " << (void *) &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << " string    = " << str << std::endl;
	std::cout << "*stringPTR = " << *stringPTR << std::endl;
	std::cout << " stringREF = " << stringREF << std::endl;
}
