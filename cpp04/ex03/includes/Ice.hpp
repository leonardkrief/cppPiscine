/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 04:39:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 05:13:24 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( const Ice& ice );
        virtual ~Ice();

        Ice& operator=( const Ice& ice );

        virtual Ice* clone() const;
        virtual void use(ICharacter& target);
};

#endif
