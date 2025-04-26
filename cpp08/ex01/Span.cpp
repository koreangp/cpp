/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:15:40 by pscala            #+#    #+#             */
/*   Updated: 2025/04/26 19:55:52 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0), _span()
{
}

Span::Span(const unsigned int N) : _size(N), _span()
{
}

Span::Span(const Span &cpy) : _size(cpy._size), _span(cpy._span)
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_size = src._size;
		_span = src._span;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(const int numb)
{
	if (_span.size() >= _size)
		throw std::out_of_range("Span is full !");
	_span.push_back(numb);
}

int Span::shortestSpan()
{

	if (_span.size() < 2 || std::adjacent_find(_span.begin(), _span.end(), std::not_equal_to<int>()) == _span.end())
	throw std::out_of_range("There is no shortest span !");

	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());

	int	shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < tmp.size() - 1; ++i)
		shortest = std::min(shortest, tmp[i + 1] - tmp[i]);
	return (shortest);
}

int Span::longestSpan()
{
	if (_span.size() < 2 || std::adjacent_find(_span.begin(), _span.end(), std::not_equal_to<int>()) == _span.end())
	throw std::out_of_range("There is no longest span !");

	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());

	return (_span[_span.back()] - _span[_span.back()]);
}

