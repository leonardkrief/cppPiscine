/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/22 12:12:29 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <vector>
#include <algorithm>

const unsigned int BANNER_SIZE = 55;

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
    std::cout << std::setw(size / 2) << std::right << title.substr(0, n / 2)
        << title.substr(n / 2, n - n / 2) << std::setw(size - size / 2 - (n - n / 2))
        << "" << std::endl;
    std::cout << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void unitTest (const Span& s, bool debug = false)
{
    std::cout << s << "\n";
    std::cout << "Shortest span: " << s.shortestSpan(debug) << "\n";
    std::cout << "Longest span: " << s.longestSpan(debug) << "\n" << std::endl;
}

void randomTest(int n = 12, int min = -100, int max = 100, bool debug = false)
{
    try
    {
        Span s(n);
        s.addRandoms(n, min, max);
        unitTest(s, debug);
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
}

void randomTests(int nbTests = 5, bool debug = false, int n = 12, int min = -100, int max = 100)
{
    std::ostringstream os;
    os << nbTests << " random tests";
    printTitle(os.str());
    if (nbTests < 1) randomTest(n, min, max);
    else
    {
        for (int i = 0; i < nbTests; i++)
        {
            randomTest(n, min, max, debug);
        }
    }
}

void bigBoyTest(bool debug = false)
{
    printTitle("big boy test");
    try
    {
        Span s(20000);
        s.addRandoms(20000, -1000000, 1000001);
        unitTest(s, debug);
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

void limitsTest()
{
    printTitle("limits test");

    try
    {
        Span s(2);
        s.addNumber(std::numeric_limits<int>::max());
        s.addNumber(std::numeric_limits<int>::min());
        unitTest(s);
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(6);
        s.addNumber(std::numeric_limits<int>::max());
        s.addNumber(0);
        s.addNumber(std::numeric_limits<int>::min());
        unitTest(s);
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

void exceptionsTests()
{
    printTitle("exceptions test");

    try
    {
        Span s(2);
        s.addNumber(std::numeric_limits<int>::max());
        s.addNumber(std::numeric_limits<int>::min());
        s.addNumber(0);
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(0);
        s.addNumber(std::numeric_limits<int>::max());
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(1);
        s.shortestSpan();
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(0);
        s.longestSpan();
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(10);
        Span c(6);
        c = s;
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(10);
        Span c(16);
        c = s;
        std::cout << "SUCCESS IS FAILURE...\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

    try
    {
        Span s(2);
        s.addNumber(0);
        s.addNumber(-2);
        unitTest(s);
        std::cout << "SUCCESS IS SUCCESS !\n";
    }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

int subjectTest()
{
    printTitle("subject test");
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    return 0;
}

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    srand(time(0));

    bigBoyTest(true);
    limitsTest();
    exceptionsTests();
    subjectTest();
    randomTests(5, true);
}
