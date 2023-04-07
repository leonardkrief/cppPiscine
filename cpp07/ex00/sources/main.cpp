/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/07 16:17:10 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

#define BANNER_SIZE 55

#define USAGE_MESSAGE "\
to run default mode: [-d, --default]\n\
to run random mode: [-r, --random]\n\n\
random mode: generates random tests. types and number of tests as options.\n\
          ./templates -r [-cifds types] [-n nb_of_tests]\n\n\
Examples: ./templates -r\n\
          ./templates -r 2\n\
          ./templates -r -c\n\
          ./templates -r -s -fdi 2"

typedef enum e_ChosenType{
    CHAR, INT, FLOAT, DOUBLE, STRING, MAX_CHOSEN_TYPE,
} e_ChosenType;

std::string types_strings[] = {
    "char",
    "int",
    "float",
    "double",
    "string",
};

static void printTitle(std::string title, bool toUpper = true, int banner_size = BANNER_SIZE)
{
    static int first;
    if (first > 0)
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
    int size (banner_size < 10 ? 10 : banner_size);
    if (n > size)
    {
        title = title.substr(0, size - 2);
        title[size - 4] = '.';
        title[size - 3] = ' ';
        n = title.size();
    }

    std::cout << std::setfill('=');
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

template <typename T>
T getValue()
{
    throw std::runtime_error("Bad request");
}

template <>
char getValue<char>()
{
    return static_cast<char>(33 + (std::rand() % (127 - 34)));
}

template <>
int getValue<int>()
{
    return std::rand();
}

template <>
float getValue<float>()
{
    int n(static_cast<float>(std::rand()));
    int d(static_cast<float>(std::rand()));
    return static_cast<float>(n / d == 0 ? 1 : d);
}

template <>
double getValue<double>()
{
    int n(static_cast<double>(std::rand()));
    int d(static_cast<double>(std::rand()));
    return static_cast<double>(n / d == 0 ? 1 : d);
}

template <>
std::string getValue<std::string>()
{
    int len = 4;
    char s[len];

    for (int i = 0; i < len; i++)
        s[i] = static_cast<char>(97 + (std::rand() % 26));
    return std::string(s);
}

void testFuncsRandom( e_ChosenType cType )
{
    switch (cType)
    {
        case CHAR:
            testFuncsTemplate(getValue<char>(), getValue<char>());
            break;
        case INT:
            testFuncsTemplate(getValue<int>(), getValue<int>());
            break;
        case FLOAT:
            testFuncsTemplate(getValue<float>(), getValue<float>());
            break;
        case DOUBLE:
            testFuncsTemplate(getValue<double>(), getValue<double>());
            break;
        case STRING:
            testFuncsTemplate(getValue<std::string>(), getValue<std::string>());
            break;
        default:;
    }
}

void testFuncsRandom_n( bool cTypeArr[MAX_CHOSEN_TYPE], int nbTests )
{
    for (int i = 0; i < MAX_CHOSEN_TYPE; i++)
    {
        if (cTypeArr[i])
        {
            printTitle(std::to_string(nbTests) + " " + types_strings[i] + " tests");
            for (int j = 0; j < nbTests; j++)
                testFuncsRandom(static_cast<e_ChosenType>(i));
        }
    }
}

int ft_usage()
{
    std::cout << USAGE_MESSAGE << std::endl;
    return 0;
}

int parse_argument(char *s, bool cTypeArr[MAX_CHOSEN_TYPE])
{
    if (s[0] == '-')
    {
        std::string str(s);

        if (str[0] != '-')
            return ft_usage();
        if (str.find_first_not_of("-cifds") != std::string::npos)
            return ft_usage();
        cTypeArr[CHAR] = (str.find('c') == std::string::npos ? cTypeArr[CHAR] : true);
        cTypeArr[INT] = (str.find('i') == std::string::npos ? cTypeArr[INT] : true);
        cTypeArr[FLOAT] = (str.find('f') == std::string::npos ? cTypeArr[FLOAT] : true);
        cTypeArr[DOUBLE] = (str.find('d') == std::string::npos ? cTypeArr[DOUBLE] : true);
        cTypeArr[STRING] = (str.find('s') == std::string::npos ? cTypeArr[STRING] : true);
    }
    return (0);
}

int randomTests(int ac, char**av)
{
    int nbTests = 5;
    bool cTypeArr[MAX_CHOSEN_TYPE] = {true, true, true, true, true};

    if (ac >= 2)
    {
        if (ac > 2 || (ac ==  2 && av[1][0] == '-'))
        {
            for (int i = 0; i < MAX_CHOSEN_TYPE; i++)
                cTypeArr[i] = false;
        }

        try { nbTests = std::stoi(av[ac - 1]); }
        catch(std::exception& e) { nbTests = 5; }

        for (int i = 1; i < ac; i++)
            parse_argument(av[i], cTypeArr);
    }
    testFuncsRandom_n(cTypeArr, nbTests);
    return 0;
}

int testFuncsRaw()
{
    printTitle("4 char tests");
    testFuncsTemplate('a', 'A');
    testFuncsTemplate(' ', '.');
    testFuncsTemplate('.', '{');
    testFuncsTemplate(';', '-');
    printTitle("4 int tests");
    testFuncsTemplate(-1, 2);
    testFuncsTemplate(846, 7654);
    testFuncsTemplate(-12, -12);
    testFuncsTemplate(std::numeric_limits<int>::max(), std::numeric_limits<int>::min());
    printTitle("4 float tests");
    testFuncsTemplate(-1.0f, 2.0f);
    testFuncsTemplate(846.3f, 846.32f);
    testFuncsTemplate(0.0f, std::numeric_limits<float>::min());
    testFuncsTemplate(std::numeric_limits<float>::max(), -std::numeric_limits<float>::max());
    printTitle("4 double tests");
    testFuncsTemplate(-1.0, 2.0);
    testFuncsTemplate(846.327647758, 846.327647);
    testFuncsTemplate(2 * std::numeric_limits<double>::min(), std::numeric_limits<double>::min());
    testFuncsTemplate(std::numeric_limits<double>::max(), -std::numeric_limits<double>::max());
    printTitle("4 string tests");
    testFuncsTemplate("axcx", "axbx");
    testFuncsTemplate("uxcx", "axbx");
    testFuncsTemplate("uxcx", "uxcz");
    testFuncsTemplate("uxcx", "uxca");
    return 0;
}

int main(int ac, char** av)
{
    if (ac == 1)
        return ft_usage();

    std::srand(std::time(0));
    std::string mode(av[1]);
    if (mode == "-d" || mode == "--default")
        return testFuncsRaw();
    if (mode == "-r" || mode == "--random")
        return randomTests(ac - 1, av + 1);
}
