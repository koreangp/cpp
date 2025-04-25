/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:35:23 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 05:15:30 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

template<typename T>
void print(const T &t)
{
	std::cout << BOLD << YELLOW << t << RESET << std::endl;
};

template<typename T, typename F>
void iter(T *array, size_t len, F f)
{
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << BOLD << GREEN << "index: " << BLUE << i << GREEN << " value: ";
		f(array[i]);
	}
};
