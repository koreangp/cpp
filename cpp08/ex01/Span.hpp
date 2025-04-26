/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:15:48 by pscala            #+#    #+#             */
/*   Updated: 2025/04/26 18:59:19 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Span
{
  private:
  	unsigned int _size;
	std::vector<int> _span;

  public:
	Span();
	Span(const unsigned int N);
	Span(const Span &cpy);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(const int numb);
	int shortestSpan();
	int longestSpan();
};
