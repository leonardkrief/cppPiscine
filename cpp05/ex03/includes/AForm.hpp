/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 04:02:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

# define PRINT_LOG 0

class AForm
{
    public:
        AForm();
        AForm( const std::string& name, const int signing_grade,
                const int executing_grade, const std::string& target = "target" );
        AForm( const AForm& f );
        virtual ~AForm();

        AForm& operator=( const AForm& f );
        friend std::ostream& operator<<( std::ostream& os, const AForm& f );

        std::string getName() const;
        std::string getTarget() const;
        int getSignature() const;
        int getSigningGrade() const;
        int getExecutingGrade() const;

        void beSigned( const Bureaucrat& b );
        bool executionRequirements( const Bureaucrat& b ) const;
        virtual bool execute(Bureaucrat const & executor) const = 0;

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

        class FormNotSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        const std::string _name;
        const std::string _target;
        bool _signature;
        const int _signing_grade;
        const int _executing_grade;

};

#endif