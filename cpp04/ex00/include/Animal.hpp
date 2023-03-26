/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:34:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 17:13:59 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    public:
        Animal();
        Animal( const std::string newType );
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string _type;
};

#endif
