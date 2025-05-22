/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:58:36 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/22 16:06:14 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::_throwIfEmptyOrOneElement(const std::string &msg) const
{
	if (_data.size() < 2)
		throw std::runtime_error(msg);
}

Span::Span() : _capacity(0)
{
	_data.reserve(0);
}

Span::Span(size_t n) : _capacity(n)
{
	_data.reserve(_capacity);
}

Span::Span(const Span &other) : _capacity(other._capacity)
{
	_data = other._data;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_data.size() >= _capacity)
		throw std::runtime_error("Cannot add new element: container has reached its maximum capacity.");
	_data.push_back(n);
}

int Span::shortestSpan() const
{
	_throwIfEmptyOrOneElement("Cannot fin shortest span: container is empty");
	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());
	size_t size = tmp.size();
	int minSpan = tmp[1] - tmp[0];
	for (size_t i = 0; i < size - 1; i++)
		minSpan = std::min(minSpan, tmp[i + 1] - tmp[i]);
	return minSpan;
}

int Span::longestSpan() const
{
	_throwIfEmptyOrOneElement("Cannot fin longest span: container is empty");
	int max = *std::max_element(_data.begin(), _data.end());
	int min = *std::min_element(_data.begin(), _data.end());
	return max - min;
}
