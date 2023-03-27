/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:34:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:13:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include "Animal.hpp"

class Brain
{
    public:
        Brain();
        Brain( const Brain &brain );
        ~Brain();

        Brain& operator=( const Brain &brain );

        void printIdea( int i ) const;
        void printIdeas( int i = 0, int j = 100 ) const;

    protected:
        std::string _ideas[100];
};

#endif
