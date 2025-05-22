/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:55:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/22 16:40:27 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define BIG_SPAN 100000
#define SMALL_SPAN 100

int main()
{
	Span sp = Span(5);
	std::cout << "Trying to insert more then Span can contains:" << std::endl;
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "Test shortest and longest span for vector {6, 3, 17, 9, 11}" << std::endl;
	std::cout << "Shortest span in big: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span in big: " << sp.longestSpan() << std::endl;

	std::cout << std::endl << "Test shortest and longest span for vectors of 100_000 elements" << std::endl;
	std::vector<int> v;
	v.reserve(BIG_SPAN);
	for (int i = 0; i < BIG_SPAN; ++i)
		v.push_back(i);
	Span bigSpan(BIG_SPAN);
	bigSpan.addNumbers(v.begin(), v.end());
	std::cout << "Shortest span in big: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span in big: " << bigSpan.longestSpan() << std::endl;

	std::cout << std::endl << "Trying to insert range of elements biger than capacity of Span:" << std::endl;
	Span smallSpan(SMALL_SPAN);
	std::vector<int> v2(10000, 42);
	try
	{
		smallSpan.addNumbers(v2.begin(), v2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
