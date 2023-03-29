/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 01:51:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>



RobotomyRequestForm::RobotomyRequestForm() :
    AForm::AForm("robotomy request form", 72, 45, "target")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] RobotomyRequestForm default constructor called" << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
    AForm::AForm("robotomy request form", 72, 45, target)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] RobotomyRequestForm info constructor called" << std::endl;
    }
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& f ) :
    AForm::AForm(f)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] RobotomyRequestForm copy constructor called" << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] RobotomyRequestForm destructor called" << std::endl;
    }
}


RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& f )
{
    this->AForm::operator=(f);
    return *this;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->executionRequirements(executor))
    {
        std::cout << ROBOTOMY_START;
        if (rand() % 2)
        {
            std::cout << ROBOTOMY_FAILURE << std::endl;
            return false;
        }
        std::cout << ROBOTOMY_SUCCESS << std::endl;
        return true;
    }
    return false;
}