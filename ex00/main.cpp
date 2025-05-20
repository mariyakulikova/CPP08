/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:54:56 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/20 17:38:01 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

#define SIZE 100

int main()
{
	std::vector<int> v;
	for (size_t i = 0; i < SIZE; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "std::vector<int>::iterator it => " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		std::vector<int>::iterator it = easyfind(v, 42000);
		std::cout << "std::vector<int>::iterator it => " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::list<int> l;
	for (size_t i = 0; i < SIZE; i++)
	{
		l.push_back(i);
	}
	try
	{
		std::list<int>::iterator it = easyfind(l, 42);
		std::cout << "std::list<int>::iterator it => " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		try
	{
		std::list<int>::iterator it = easyfind(l, 42000);
		std::cout << "std::list<int>::iterator it => " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
