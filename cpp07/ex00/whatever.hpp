/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:33:52 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 00:17:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
};

template<typename T>
T min(T a, T b)
{
	return ((a < b) ? a : b);
};

template<typename T>
T max(T a, T b)
{
	return ((a > b) ? a : b);
};
