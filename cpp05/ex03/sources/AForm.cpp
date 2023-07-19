/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/06/22 15:24:13 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <iomanip>

AForm::AForm() :
    _name("random"),
    _target("target"),
    _signature(false),
    _signing_grade(1),
    _executing_grade(1)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] AForm default constructor called" << std::endl;
    }
}

AForm::AForm( const std::string& name, const int signing_grade,
        const int executing_grade, const std::string& target ) :
    _name(name),
    _target(target),
    _signature(false),
    _signing_grade(signing_grade),
    _executing_grade(executing_grade)
{
    if (signing_grade < 1 || executing_grade < 1)
    {
        throw AForm::GradeTooHighException();
    }
    else if (signing_grade > 150 || executing_grade > 150)
    {
        throw AForm::GradeTooLowException();
    }
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] AForm info constructor called" << std::endl;
    }
}

AForm::AForm( const AForm& f ) :
    _name(f._name),
    _target(f._target),
    _signing_grade(f._signing_grade),
    _executing_grade(f._executing_grade)
{
    _signature = f._signature;
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] AForm copy constructor called" << std::endl;
    }
}

AForm::~AForm()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] AForm destructor called" << std::endl;
    }
}


AForm& AForm::operator=( const AForm& f )
{
    if (this != &f)
    {
        _signature = f._signature;
    }
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] AForm copy assignment operator called"
            << std::endl;
    }
    return *this;
}

std::string AForm::getName() const
{
    return "'" + _name + "'";
}

std::string AForm::getTarget() const
{
    return _target;
}

int AForm::getSignature() const
{
    return _signature;
}

int AForm::getSigningGrade() const
{
    return _signing_grade;
}

int AForm::getExecutingGrade() const
{
    return _executing_grade;
}

void AForm::beSigned( const Bureaucrat& b )
{
    b.signForm(*this);
    if (b.getGrade() > _signing_grade)
    {
        throw AForm::GradeTooLowException();
    }
    _signature = true;
}

bool AForm::executionRequirements( const Bureaucrat& b ) const
{
    std::cout << this->getName() << "    ["
        << _target << "]\n  execution permission asked by " << b.getName()
        <<"...\n    Checking requirements...\n";
    if (_signature && b.getGrade() <= _executing_grade)
    {
        std::cout << "    SUCCESS: [" << b.getName() << "] executed ["
            << this->getName() << "]...\n";
        return true;
    }
    std::cout << "    ERROR: [" << b.getName() << "] is unable to execute "
        << this->getName() << std::endl << "      ";
    if (!_signature)
    {
        throw AForm::FormNotSigned();
    }
    throw AForm::GradeTooLowException();
    return false;
}

std::ostream& operator<<( std::ostream& os, const AForm& f )
{
    std::string signature = (f.getSignature() == false ? "NO" : "YES");
    os << f.getName()
        << std::setw(30) << std::left << "\n  signed: " << signature
        << std::setw(30) << std::left << "\n  target: " << f.getTarget()
        << "\n  required grade to sign:    " << f.getSigningGrade()
        << "\n  required grade to execute: " << f.getExecutingGrade();
    return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm::Exception: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm::Exception: Grade is too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "AForm::Exception: Form is not signed";
}