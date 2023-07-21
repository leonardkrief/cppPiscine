/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/07/21 16:46:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <list>

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


void    testList(void)
{
    printTitle("list test");
    std::list<int>    mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "top = " << *(std::prev(mlist.end())) << std::endl;
        
    mlist.pop_back();

    std::cout << "size = " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(-12);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void    testSubject(void)
{
    printTitle("subject test");
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top = " << mstack.top() << std::endl;
        
    mstack.pop();

    std::cout << "size = " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(-12);
    mstack.push(0);

    MutantStack<int>::iterator  it = mstack.begin();
    MutantStack<int>::iterator  ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack <int> s(mstack);
}

int main(void)
{
    testSubject();
    testList();
    return (0);
}