/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:23:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 06:50:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character( const std::string& name );
        Character( const Character& character );
        virtual ~Character();
        
        Character& operator=( const Character& character );
        
        virtual const std::string& getName() const;
        virtual void equip( AMateria* m );
        virtual void unequip( int idx );
        virtual void use( int idx, ICharacter& target );
        virtual void printInventory(void) const;

    private:
        std::string _name;
        AMateria* _inventory[4];
};

#endif
