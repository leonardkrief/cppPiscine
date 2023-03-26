/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:45:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:22:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

// C++11
// use of override specifier to show our intention of
// overriding a virtual function, eg:
// virtual void makeSound() override;
class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        void makeSound() const;
};

#endif