/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/06 00:03:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
    public:
        Data();
        ~Data();
        const int& getValue() const;

    private:
        Data( const Data& s );
        Data& operator=( const Data& s );

        int _data;

        const static bool _print_log_ = false;
};

#endif