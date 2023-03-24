/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 02:48:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap( const std::string name );
        DiamondTrap( const DiamondTrap& r );
        DiamondTrap& operator=( const DiamondTrap& r );
        ~DiamondTrap();

        void whoAmI() const;

        using ScavTrap::attack;
        void print() const;

    private:
        DiamondTrap();
        std::string _name;
};

#endif