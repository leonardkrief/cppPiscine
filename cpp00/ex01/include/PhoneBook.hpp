#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(); // construct a PhoneBook
		~PhoneBook(); // destroy a PhoneBook
		std::string	welcome(void) const;
		void		addEntry(void);		// add a new contact
		void		previewContacts(void) const;
		void		searchEntry(void) const;

	private:
		Contact	_contacts[8];	// pointer to the elements
		int		_size;			// number of contacts
};


#endif