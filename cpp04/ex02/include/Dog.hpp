/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:45:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/26 19:29:06 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

// C++11
// use of override specifier to show our intention of
// overriding a virtual function, eg:
// virtual void makeSound() override;
class Dog : public Animal
{
    public:
    
        Dog();
        Dog( const Dog& dog );
        ~Dog();

        Dog& operator=( const Dog& dog );

        void printIdeas( int i = 0, int j = 5) const;
        virtual void makeSound() const;

    protected:
        Brain* _brain;
};

#endif