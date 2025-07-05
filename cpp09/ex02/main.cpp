/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:31:21 by pscala            #+#    #+#             */
/*   Updated: 2025/07/05 01:11:12 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	parseArgs(char c)
{
	if (!isdigit(static_cast<unsigned char>(c)))
		return false;
}


int main(int ac, char **av)
{
	if (ac > 2)
	{
		std::ostringstream oss;
		for (int i = 1; i < ac; ++i)
		{
			if (!parseArgs(av[i][0]))
			{
				std::cerr << BRED << "Error: Wrong argument" << RESET << std::endl;
				return (1);
			}
		}
	}
	std::cerr << BRED << "Error: Wrong number of arguments" << RESET << std::endl;
	return (1);
}
