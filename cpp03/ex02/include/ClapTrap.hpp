/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 04:23:51 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

enum Action_e {ATTACK, REPAIR, DAMAGE};

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap( const std::string name );
        ClapTrap( const ClapTrap& r );
        ClapTrap& operator=( const ClapTrap& r );
        ~ClapTrap();

        std::string getName() const;
        int getHp() const;
        int getEnergy() const;
        int getAttack() const;
        void setName( const std::string newName );
        void setHp( const int newHp );
        void setEnergy( const int newEnergy );
        void setAttack( const int newAttack );

        bool hasEnergy( const Action_e action ) const;
        bool isAlive( const Action_e action ) const;

        void attack( const std::string& target );
        void takeDamage( const unsigned int amount );
        void beRepaired( const unsigned int amount );

        virtual void print() const;

    protected:
        std::string _name;
        int _hp;
        int _energy;
        int _attack;

};

#endif