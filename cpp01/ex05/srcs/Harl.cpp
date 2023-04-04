/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:10:56 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 16:15:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iomanip>

void Harl::_debug( void ) const
{
	std::cout << message_strings[static_cast<int>(DEBUG)] << std::endl;
}

void Harl::_info( void ) const
{
	std::cout << message_strings[static_cast<int>(INFO)] << std::endl;
}

void Harl::_warning( void ) const
{
	std::cout << message_strings[static_cast<int>(WARNING)] << std::endl;
}

void Harl::_error( void ) const
{
	std::cout << message_strings[static_cast<int>(ERROR)] << std::endl;
}

void Harl::_usage( void ) const
{
	std::cout << message_strings[static_cast<int>(USAGE)] << std::endl;
}

static std::string& toUpper(std::string &str)
{
    for (size_t i = 0; i < str.size(); ++i)
        str[i] = toupper(str[i]);
    return str;
}

Level_e	getLevel( std::string level )
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; ++i)
	{
		if (toUpper(level) == levels[i])
			return (static_cast<Level_e>(i));
	}
	return USAGE;
}

void	printHeader( std::string level )
{
	std::string print(level);
	size_t	total_width (10);

	if (level.size() >= total_width)
		print = level.substr(0, total_width - 2) + ".";

	int	left_width  ((total_width + print.size()) / 2);
	int	right_width (total_width - left_width);
	std::cout << "[ " << std::setw(left_width) << std::right
		<< print
		<< std::setw(right_width + 4) << " ]   ";
}

void Harl::complain( std::string level ) const
{
	Level_e	lvl(getLevel(level));
	message_func f[] = { &Harl::_debug, &Harl::_info,
		&Harl::_warning, &Harl::_error, &Harl::_usage };

	printHeader(level);
	(this->*(f[lvl]))();
}