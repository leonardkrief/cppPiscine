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

#include "Data.hpp"
#include "Serializer.hpp"
#include <iomanip>
#include <iostream>

int BANNER_SIZE = 55;

static void printTitle(std::string title, bool toUpper = true, bool newline = true)
{
    static int first;
    if (first > 0 && newline)
        std::cout << std::endl;
    else
        first++;

    title = " " + title + " ";
    if (toUpper)
    {
        for (int i = 0; title[i]; i++)
        {
            title[i] = toupper(title[i]);
        }
    }
    int n = title.size();
    int size (BANNER_SIZE < 10 ? 10 : BANNER_SIZE);
    if (n > size)
    {
        title = title.substr(0, size - 2);
        title[size - 4] = '.';
        title[size - 3] = ' ';
        n = title.size();
    }

    std::cout << std::setfill('=');
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

static void testPtr()
{
    Data* dataPtr = new Data();
    uintptr_t int_Ptr = 0x0u;

    printTitle("basic test");
    BANNER_SIZE = 30;

    printTitle("initial state");
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr
        << "    value = " << std::dec << dataPtr->getValue() << std::endl;

    printTitle("data* to uintptr_t");
    int_Ptr = Serializer::serialize(dataPtr);
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr
        << "    value = " << std::dec << dataPtr->getValue() << std::endl;
    printTitle("uintptr_t back to data*");
    dataPtr = Serializer::deserialize(int_Ptr);
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr
        << "    value = " << std::dec << dataPtr->getValue() << std::endl << std::endl;
    delete dataPtr;

    BANNER_SIZE = 55;
}

static void testReallocPtr()
{
    Data* dataPtr = new Data();
    uintptr_t int_Ptr = 0x0u;

    printTitle("realloc test");
    BANNER_SIZE = 30;

    printTitle("initial state");
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr
        << "    value = " << std::dec << dataPtr->getValue() << std::endl;

    printTitle("data* to null");
    int_Ptr = Serializer::serialize(dataPtr);
    dataPtr = 0;
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr << std::endl;

    printTitle("data* get its data back");
    dataPtr = Serializer::deserialize(int_Ptr);
    std::cout << "int_ptr = " << std::showbase << std::hex << int_Ptr << std::endl;
    std::cout << "dataPtr = " << std::showbase << std::hex << dataPtr
        << "    value = " << std::dec << dataPtr->getValue() << std::endl << std::endl;
    delete dataPtr;

    BANNER_SIZE = 55;
}

// A reinterpret_cast is inherently machine dependent. Safely using
// reinterpret_cast requires completely understanding the types involved
// as well as the details of how the compiler implements the cast.
static void testWarning()
{
    printTitle("warning test");

    char c[sizeof(double)];
    std::memcpy(c, "\x3f\xf0\x00\x00\x00\x00\x00\x00", sizeof(double)); // Initialize with specific bytes
    //                63  240 0   0   0   0   0   0
    // WARNING: Undefined behavior depending on the machine, compiler and endianness
    double* dp = reinterpret_cast<double*>(c);

    int* u = reinterpret_cast<int*>(c);
    std::cout << "Value of u[0]: " << u[0] << std::endl;
    std::cout << "Value of u[1]: " << u[1] << std::endl;
    std::cout << "Value of the double: " << *dp << std::endl;
}

int main()
{
    testPtr();
    testReallocPtr();
    testWarning();
    exit(EXIT_SUCCESS);
}