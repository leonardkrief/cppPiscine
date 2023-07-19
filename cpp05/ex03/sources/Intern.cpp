/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:37:02 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 05:48:52 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

Intern::Intern()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Intern default constructor called" << std::endl;
    }
}

Intern::Intern( const Intern& b )
{
    (void) b;
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Intern copy constructor called" << std::endl;
    }
}

Intern::~Intern()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Intern destructor called" << std::endl;
    }
}

Intern& Intern::operator=( const Intern& b )
{
    (void)b;
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] Intern copy assignment operator called"
            << std::endl;
    }
    return *this;
}

static AForm* newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

// AForm* Intern::newShrubbery(const std::string& target)
// {
// 	return (new ShrubberyCreationForm(target));
// }

// AForm* Intern::newRobotomy(const std::string& target)
// {
// 	return (new RobotomyRequestForm(target));
// }

// AForm* Intern::newPresidential(const std::string& target)
// {
// 	return (new PresidentialPardonForm(target));
// }

static int getFormIndex( const std::string& formName )
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int i(-1);

    while (++i < 3)
    {
        if (formName == names[i])
            return i;
    }
    return -1;
}

AForm* Intern::makeForm( const std::string& formName,
        const std::string& formTarget ) const
{
    MakeFormFunction makeForm[] = {
        &newShrubbery,
        &newRobotomy,
        &newPresidential
    };

    int i(getFormIndex(formName));
    if (i == -1)
    {
        std::cout << "ERROR: Intern unable to create form '" << formName
            << " form'  [" << formTarget << "]\n  ";
        throw Intern::UnknownFormName();
    }
    std::cout << "Intern creates '" << formName
        << " form'  [" << formTarget << "]" << std::endl;
    return makeForm[i](formTarget);
}

const char* Intern::UnknownFormName::what() const throw()
{
    return "Intern::UnknownFormName: Form name does not exist";
}
