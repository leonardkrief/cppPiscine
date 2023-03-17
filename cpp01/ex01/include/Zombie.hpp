#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie
{
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	announce( void ) const;
		void	setName( std::string name);

	private:
		std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );
void	announceHorde( int N, Zombie* horde );

#endif