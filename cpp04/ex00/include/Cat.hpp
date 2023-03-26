/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:45:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 17:15:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

// C++11
// use of override specifier to show our intention of
// overriding a virtual function, eg:
// virtual void makeSound() override;
class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        virtual void makeSound() const;
};

#endif