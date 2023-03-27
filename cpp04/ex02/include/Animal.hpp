/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:34:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:48:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    public:
        Animal();
        Animal( const Animal& animal );
        Animal( const std::string newType );
        virtual ~Animal();

        Animal& operator=( const Animal& animal );

        std::string getType() const;
        virtual void makeSound() const = 0;

    protected:
        std::string _type;
};

#endif
