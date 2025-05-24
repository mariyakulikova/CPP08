/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:39:08 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/24 15:56:08 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "Example from subject:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "List:" << std::endl;
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);
	std::list<int>::iterator lit = l.begin();
	std::list<int>::iterator lite = l.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << std::endl << "const MutantStack:" << std::endl;
	const MutantStack<int> cmstack(mstack);
	std::cout << "Top element: "  << cmstack.top() << std::endl;
	std::cout << "MutantStack size: " << cmstack.size() << std::endl;
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
	std::cout << *cit << std::endl;
	++cit;
	}

	std::cout << std::endl << "MutantStack and reverse iterator:" << std::endl;
	MutantStack<int> mstack2(mstack);
	std::cout << "Top element: " << cmstack.top() << std::endl;
	std::cout << "MutantStack size: " << cmstack.size() << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack2.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack2.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << std::endl << "const MutantStack and reverse iterator:" << std::endl;
	const MutantStack<int> cmstack2(mstack);
	std::cout << "Top element: " << cmstack2.top() << std::endl;
	std::cout << "MutantStack size: " << cmstack2.size() << std::endl;
	MutantStack<int>::const_reverse_iterator crit = cmstack2.rbegin();
	MutantStack<int>::const_reverse_iterator crite = cmstack2.rend();
	++crit;
	--crit;
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	return 0;
}
