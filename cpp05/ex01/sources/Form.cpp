/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:37:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/28 00:24:00 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <iomanip>

Form::Form() :
    _name("random"),
    _signature(false),
    _signing_grade(1),
    _executing_grade(1)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Form default constructor called" << std::endl;
    }
}

Form::Form( const std::string& name, const int signing_grade,
    const int executing_grade ) :
    _name(name),
    _signature(false),
    _signing_grade(signing_grade),
    _executing_grade(executing_grade)
{
    if (signing_grade < 1 || executing_grade < 1)
    {
        throw Form::GradeTooHighException();
    }
    else if (signing_grade > 150 || executing_grade > 150)
    {
        throw Form::GradeTooLowException();
    }
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Form info constructor called" << std::endl;
    }
}

Form::Form( const Form& f ) :
    _name(f._name),
    _signing_grade(f._signing_grade),
    _executing_grade(f._executing_grade)
{
    _signature = f._signature;
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Form copy constructor called" << std::endl;
    }
}

Form::~Form()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Form destructor called" << std::endl;
    }
}


Form& Form::operator=( const Form& f )
{
    if (this != &f)
    {
        _signature = f._signature;
    }
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Form copy assignment operator called"
            << std::endl;
    }
    return *this;
}

std::string Form::getName() const
{
    return "'" + _name + "'";
}

int Form::getSignature() const
{
    return _signature;
}

int Form::getSigningGrade() const
{
    return _signing_grade;
}

int Form::getExecutingGrade() const
{
    return _executing_grade;
}


void Form::beSigned( const Bureaucrat& b )
{
    b.signForm(*this);
    if (b.getGrade() > _signing_grade)
    {
        throw Form::GradeTooLowException();
    }
    _signature = true;
}

std::ostream& operator<<( std::ostream& os, const Form& f )
{
    std::string signature = (f.getSignature() == false ? "NO" : "YES");
    os << f.getName()
        << std::setw(30) << std::left << "\n  signed: " << signature
        << "\n  required grade to sign:    " << f.getSigningGrade()
        << "\n  required grade to execute: " << f.getExecutingGrade();
    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form::Exception: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form::Exception: Grade is too low";
}