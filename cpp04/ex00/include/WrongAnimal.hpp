/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:34:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:36:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal( std::string newType );
        ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;

    protected:
        std::string _type;
};

#endif
