/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:37:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/06/22 15:07:54 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <iomanip>

Bureaucrat::Bureaucrat() : _name("random"), _grade(150)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Bureaucrat default constructor called" << std::endl;
    }
}

Bureaucrat::Bureaucrat( const std::string& name, const int grade ) :
    _name(name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Bureaucrat info constructor called" << std::endl;
    }
}

Bureaucrat::Bureaucrat( const Bureaucrat& b ) :
    _name(b._name),
    _grade(b._grade)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Bureaucrat copy constructor called" << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Bureaucrat destructor called" << std::endl;
    }
}


Bureaucrat& Bureaucrat::operator=( const Bureaucrat& b )
{
    if (this != &b)
    {
        _grade = b._grade;
    }
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Bureaucrat copy assignment operator called"
            << std::endl;
    }
    return *this;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& b )
{
    std::string name = b.getName() + ",";
    os << std::setw(12) << std::left << name << " bureaucrat grade " << b.getGrade() << ".";
    return os;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::upGrade()
{
    if (_grade == 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::downGrade()
{
    if (_grade == 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm( const AForm& f ) const
{
    if (f.getSigningGrade() < _grade)
    {
        std::cout << "[" << _name << "]  couldn't sign "
            << f.getName() << " because its grade is too low\n  * grade "
            << f.getSigningGrade() << " or more is required *\n    ";
    }
    else
    {
        std::cout << "[" << _name << "]  signed " << f.getName()
        << "  [" << f.getTarget() << "]\n";
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::Exception: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::Exception: Grade is too low";
}