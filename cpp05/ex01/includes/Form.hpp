/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/28 01:01:12 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

# define PRINT_LOG 0

class Form
{
    public:
        Form();
        Form( const std::string& name, const int signing_grade,
                const int executing_grade );
        Form( const Form& f );
        ~Form();

        Form& operator=( const Form& f );
        friend std::ostream& operator<<( std::ostream& os, const Form& f );

        std::string getName() const;
        int getSignature() const;
        int getSigningGrade() const;
        int getExecutingGrade() const;

        void beSigned( const Bureaucrat& b );

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _signature;
        const int _signing_grade;
        const int _executing_grade;

};

#endif