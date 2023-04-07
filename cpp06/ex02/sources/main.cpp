/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 03:38:20 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iomanip>
#include <iostream>
#include <random>

Base* generate()
{
    int random = std::rand() % 3;

    if (random == 0)
    {
        std::cout << "Randomly generated A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Randomly generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Randomly generated C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "     pointer_type:       A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "     pointer_type:       B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "     pointer_type:       C*" << std::endl;
    else
        std::cout << "     pointer_type: unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "     reference_type:      A&" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "     reference_type:      B&" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "     reference_type:      C&" << std::endl;
    }
    catch(const std::bad_cast& e) {}
}

static void testFull( int numberOfTests )
{
    srand(time(NULL));
    for (int i = 0; i < numberOfTests; i++)
    {
        std::cout << "(" << std::setfill('0') << std::setw(2) << i + 1 << ") ";
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
}

int main()
{
    testFull(10);
    exit(EXIT_SUCCESS);
}