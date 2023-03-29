/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 05:40:05 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() :
    AForm::AForm("presidential pardon form", 25, 5, "target")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] PresidentialPardonForm default constructor called" << std::endl;
    }
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) :
    AForm::AForm("presidential pardon form", 25, 5, target)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] PresidentialPardonForm info constructor called" << std::endl;
    }
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& f ) :
    AForm::AForm(f)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] PresidentialPardonForm copy constructor called" << std::endl;
    }
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] PresidentialPardonForm destructor called" << std::endl;
    }
}


PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& f )
{
    this->AForm::operator=(f);
    return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->executionRequirements(executor))
    {
        std::cout << PARDON_MESSAGE << std::endl;
        return true;
    }
    return false;
}