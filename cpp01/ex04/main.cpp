/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 23:04:49 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main( int ac, char **av )
{
    if (ac != 4)
    {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return -1;
    }
    // Check if s1 is non null.
    // Else, infinite loop could occur
    if (!av[2][0])
    {
        std::cerr << "Error: searched string is blank." << std::cout;
        return -1;
    }
    std::string		infile_name(av[1]);
    std::fstream	infile(infile_name, std::ios::in);
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open file: '"
            << av[1] << "'" << std::endl;
        return -1;
    }
    std::cout << "Opened in read mode: '"
        << av[1] << "'" << std::endl;

    std::string		outfile_name(av[1]);
    outfile_name += ".replace";
    std::fstream	outfile(outfile_name, std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) 
    {
        std::cerr << "Error: cannot open file: '"
            << av[1] << ".replace'" << std::endl;
        return -1;
    }
    std::cout << "Opened in write mode and truncated: '"
        << outfile_name << "'" << std::endl;

    std::string	line;
    std::string	s1(av[2]);
    std::string	s2(av[3]);
    size_t		pos;

    // Need to load the whole file at once inside line
    // Else, we wont be able to replace strings
    // such as "*\n*", because getline would cut at '\n'
    while (std::getline(infile, line, '\0'))
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
