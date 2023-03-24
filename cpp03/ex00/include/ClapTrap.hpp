/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/22 18:00:06 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

enum Action_e {ATTACK, REPAIR, DAMAGE};

class ClapTrap
{;
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( ClapTrap& r );
        ClapTrap& operator=( ClapTrap& r );
        ~ClapTrap();

        std::string getName() const;
        int getHp() const;
        int getEnergy() const;
        int getAttack() const;
        void setName( std::string newName );
        void setHp( int newHp );
        void setEnergy( int newEnergy );
        void setAttack( int newAttack );
        
        bool hasEnergy( Action_e action ) const;
        bool isAlive( Action_e action ) const;

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

    private:
        std::string _name;
        int _hp;
        int _energy;
        int _attack;

};

#endif