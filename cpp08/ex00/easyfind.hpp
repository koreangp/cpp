/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:20:47 by pscala            #+#    #+#             */
/*   Updated: 2025/04/26 18:16:01 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Color.hpp"

template <typename container>
typename container::iterator easyfind(container &tab,int value)
{
	typename container::iterator it = std::find(tab.begin(), tab.end(), value);

	if (it == tab.end())
		throw std::out_of_range("Element not found in container");

	return (it);
};
