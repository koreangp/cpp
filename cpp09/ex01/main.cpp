/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:12:39 by pscala            #+#    #+#             */
/*   Updated: 2025/05/23 01:37:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			RPN operation(av[1]);
			return (0);
		}

		catch(const std::exception& e)
		{
			std::cerr << BOLD << RED << e.what() << RESET << std::endl;
			return (1);
		}
	}
	std::cerr << BOLD << RED << "Error: no operation passed" << RESET << std::endl;
	return (1);
}
