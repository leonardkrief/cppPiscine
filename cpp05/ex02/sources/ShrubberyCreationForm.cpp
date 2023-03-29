/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:31 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 04:05:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm::AForm("shrubbery creation form", 145, 137, "target")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] ShrubberyCreationForm default constructor called" << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) :
    AForm::AForm("shrubbery creation form", 145, 137, target)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] ShrubberyCreationForm info constructor called" << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& f ) :
    AForm::AForm(f)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] ShrubberyCreationForm copy constructor called" << std::endl;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void*)this
            << "] ShrubberyCreationForm destructor called" << std::endl;
    }
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& f )
{
    this->AForm::operator=(f);
    return *this;
}

static const char* getTree1()
{
    return TREE_1;
}

static const char* getTree2()
{
    return TREE_2;
}

static const char* getTree3()
{
    return TREE_3;
}

static const char* getTree4()
{
    return TREE_4;
}

static const char* getTree5()
{
    return TREE_5;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    const char* (*trees[])() = {&getTree1, &getTree2, &getTree3, &getTree4, &getTree5};
    const std::string filename = this->getTarget() + "_shrubbery";
    if (this->executionRequirements(executor))
    {
        std::ofstream myFile(filename);
        if (!myFile.is_open())
        {
            throw std::ios_base::failure("Unable to open file: " + filename);
        }
        myFile << trees[rand() % 5]();
        myFile.close();
        return true;
    }
    return false;
}