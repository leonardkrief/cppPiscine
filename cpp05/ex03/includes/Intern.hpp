/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:30:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 02:06:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <ostream>

class AForm;

class Intern
{
    public:
        Intern();
        Intern( const Intern& b );
        ~Intern();

        Intern& operator=( const Intern& b );

        AForm* makeForm( const std::string& formName,
                const std::string& formTarget ) const;

        class UnknownFormName : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

typedef AForm* (*MakeFormFunction)(std::string);

#endif