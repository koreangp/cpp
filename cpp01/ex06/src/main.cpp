/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:44:41 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 11:33:25 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << BOLD << "Error : Wrong number of arguments : " << ac - 1 << " out of 1" << RESET << std::endl;
		return (1);
	}

	Harl chill;
	std::string message = av[1];
	int level;

	level = chill.complain(message);

	switch (level)
	{
	case 0:
		chill.complain("INFO");

	case 1:
		chill.complain("WARNING");

	case 2:
		chill.complain("ERROR");
		break;

	case -1:
		std::cout << BOLD << "\n" << "[ Probably complaining about insignificant problems ]" << "\n" << RESET << std::endl;
	}

	return (0);
}
