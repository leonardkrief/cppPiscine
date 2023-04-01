#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();

		void	init(void);
		void	preview(int) const;
		void	print(int) const;
		void	setIndex(int);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		int _index;
		std::string _printLen(std::string str) const;
		std::string _getInput(std::string str) const;
};

#endif