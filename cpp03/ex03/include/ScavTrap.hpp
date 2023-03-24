/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 04:54:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( const std::string name );
        ScavTrap( const ScavTrap& r );
        ScavTrap& operator=( const ScavTrap& r );
        ~ScavTrap();

        bool getGuardingGate() const;
        void setGuardingGate( const bool newGuard );
        void guardGate();

        void attack( const std::string& target );

        void print() const;

    protected:
        bool _guardingGate;
};

#endif