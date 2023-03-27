/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:23:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 06:48:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource( const MateriaSource& matsource );
        virtual ~MateriaSource();

        MateriaSource& operator=( const MateriaSource& matsource );

        virtual void learnMateria( AMateria* );
        virtual AMateria* createMateria( const std::string& type );
    
    private:
        AMateria* _materias[4];
};

#endif
