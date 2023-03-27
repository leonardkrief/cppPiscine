/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 04:39:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 05:19:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( const Cure& cure );
        virtual ~Cure();

        Cure& operator=( const Cure& cure );

        virtual Cure* clone() const;
        virtual void use(ICharacter& target);
};

#endif
