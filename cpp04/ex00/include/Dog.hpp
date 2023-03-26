/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:45:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 16:56:25 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

// C++11
// use of override specifier to show our intention of
// overriding a virtual function, eg:
// virtual void makeSound() override;
class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        virtual void makeSound() const;
};

#endif