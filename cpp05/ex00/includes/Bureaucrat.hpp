/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:30:29 by lkrief            #+#    #+#             */
/*   Updated: 2023/06/22 14:35:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <ostream>

# define PRINT_LOG 0

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat( const std::string& name, const int grade );
        Bureaucrat( const Bureaucrat& b );
        Bureaucrat& operator=( const Bureaucrat& b );
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void upGrade();
        void downGrade();

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
        int _grade;
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b );

#endif