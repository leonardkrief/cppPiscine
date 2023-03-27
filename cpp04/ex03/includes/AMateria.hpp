/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:23:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 06:45:21 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

# define PRINT_LOG 0

class ICharacter;

class AMateria
{
    public:
        AMateria();
        AMateria( const std::string& type );
        AMateria( const AMateria& materia );
        virtual ~AMateria();

        AMateria& operator=( const AMateria& materia );

        const std::string& getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

    protected:
        std::string _type;
};

#endif
