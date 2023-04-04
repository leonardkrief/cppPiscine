/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:10:06 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 16:19:49 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

// (C++11)
// 'scoped enumerations' or 'strongly typed enumerations' are forbidden
// I then have to use a regular enum, the enumerator values are not
// scoped and can be accessed using just their names (e.g., DEBUG, INFO, etc.).
// ---> higher risk of naming conflicts with other parts of the code.
//
// enum class Level
// {
// 	DEBUG, INFO, WARNING, ERROR, USAGE
// };

enum Level_e
{
    DEBUG, INFO, WARNING, ERROR, USAGE
};

const std::string message_strings[] = {
    "DEBUG MESSAGE",
    "INFO MESSAGE",
    "WARNING MESSAGE",
    "ERROR MESSAGE",
    "Usage:\t./harl [level = {DEBUG, INFO, WARNING, ERROR}]"
};

// const std::string message_strings[] = {
//     "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
// ketchup burger. I really do!",
//     "I cannot believe adding extra bacon costs more money. You didn't put\
// enough bacon in my burger! If you did, I wouldn't be asking for more!",
//     "I think I deserve to have some extra bacon for free. I've been coming for\
// years whereas you started working here since last month.",
//     "This is unacceptable! I want to speak to the manager now.",
//     "Usage:\t./harl [level = {DEBUG, INFO, WARNING, ERROR}]"
// };

class Harl
{
    typedef void (Harl::*message_func)(void) const;
    public:
        Harl(){ std::cout
            << "[" << (void *)this << "] Harl woke up" << std::endl; };
        ~Harl(){ std::cout
            << "\n[" << (void *)this << "] Harl fell asleep" << std::endl; };
        void complain( std::string level ) const;

    private:
        void _debug( void ) const;
        void _info( void ) const;
        void _warning( void ) const;
        void _error( void ) const;
        void _usage( void ) const;
    
};

Level_e	getLevel( std::string level );
void	printHeader( std::string level );


// (C++11)
// unordered_map class
//
// #include <unordered_map>
// class MessageMap
// {
// 	public:
// 		MessageMap()
// 		{
// 			_messages = {
// 				{Level::DEBUG, "Debug message"},
// 				{Level::INFO, "Info message"},
// 				{Level::WARNING, "Warning message"},
// 				{Level::ERROR, "Error message"}
// 			};
// 		}
// 	const std::string& GetMessage(Level level) const
// 	{
// 		auto it = _messages.find(level);
// 		if (it != _messages.end())
// 		{
// 			return it->second;
// 		}
// 		else
// 		{
// 			static const std::string empty_string;
// 			return empty_string;
// 		}
// 	}

// 	private:
// 		std::unordered_map<Level, std::string>	_messages;
// };

#endif