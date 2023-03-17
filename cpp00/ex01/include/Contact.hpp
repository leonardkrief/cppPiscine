#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact();					// construct a Contact
		~Contact();					// destruct a Contact
		void	init(void);			// init a Contact
		void	preview(int) const;	// preview a Contact
		void	print(int) const;	// print a Contact
		void	setIndex(int);		// set index

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_index;
		std::string _printLen(std::string str) const;
		std::string _getInput(std::string str) const;
};

#endif