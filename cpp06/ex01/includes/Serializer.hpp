/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/06 00:02:36 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>

class Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        ~Serializer();
        Serializer();
        Serializer( const Serializer& s );
        Serializer& operator=( const Serializer& s );

        const static bool _print_log_ = false;
};


#endif