/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:41:21 by mkulikov          #+#    #+#             */
/*   Updated: 2025/05/24 15:25:28 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const;
	const_iterator end() const;

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
