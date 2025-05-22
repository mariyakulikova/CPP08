/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:58:54 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/22 16:41:42 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	size_t _capacity;
	std::vector<int> _data;
	void _throwIfEmptyOrOneElement(const std::string& msg) const;
public:
	Span();
	Span(size_t n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	void addNumber(int n);

	template <typename T>
	void addNumbers(T first, T last) {
		if (static_cast<size_t>(std::distance(first, last)) + _data.size() > _capacity)
			throw std::runtime_error("Cannot insert range of elements: range is greater than Span capacity.");
		_data.insert(_data.end(), first, last);
	}

	int shortestSpan() const;
	int longestSpan() const;
};

#endif



