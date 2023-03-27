/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:34:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:43:39 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
    public:
        AAnimal();
        AAnimal( const AAnimal& Aanimal );
        AAnimal( const std::string newType );
        virtual ~AAnimal();

        AAnimal& operator=( const AAnimal& Aanimal );

        std::string getType() const;
        virtual void makeSound() const;

    protected:
        std::string _type;
};

#endif
