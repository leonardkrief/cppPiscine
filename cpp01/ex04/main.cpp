/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/17 07:58:36 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return -1;
	}

	std::string		infile_name(av[1]);
	std::fstream	infile(infile_name, std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "'" << av[1]
		<< "': issue while opening the file" << std::endl;
		return -1;
	}
	std::cout << "'" << av[1]
		<< "': successfully opened in read mode" << std::endl;

	std::string		outfile_name(av[1]);
	outfile_name += ".replace";
	std::fstream	outfile(outfile_name, std::ios::out | std::ios::trunc);
	if (!outfile.is_open()) 
	{
		std::cerr << "'" << av[1]
		<< "': issue while opening the file" << std::endl;
		return -1;
	}
	std::cout << "'" << outfile_name
		<< "': successfully opened and truncated in write mode" << std::endl;

	std::string	line;
	std::string	s1(av[2]);
	std::string	s2(av[3]);
	size_t		pos;
	while (std::getline(infile, line))
	{
		if (!infile.eof()) {
			line += '\n';
		}
		do {
			pos = line.find(s1);
			if (pos == std::string::npos) {
				outfile << line;
			}
			else
			{
				outfile << line.substr(0, pos);
				outfile << s2;
				line = line.substr(pos + s1.size());
			}
		} while (pos != std::string::npos);
	}
	// not necessary to close the files manually as std::fstream objects are RAII
	// objects: https://stackoverflow.com/questions/4802494/do-i-need-to-close-a-stdfstream
	// infile.close();
	// outfile.close();
}
