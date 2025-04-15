/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:24:55 by pscala            #+#    #+#             */
/*   Updated: 2025/02/06 11:47:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(int ac, char **av)
{
	if (ac != 9)
	{
		std::cerr << BOLD << RED << "Error : Invalid number of argument : " << YELLOW << ac - 1 << RED << ";\n8 needed" << RESET << std::endl;
		return (1);
	}

	Point a(std::atof(av[1]), std::atof(av[2]));
	Point b(std::atof(av[3]), std::atof(av[4]));
	Point c(std::atof(av[5]), std::atof(av[6]));
	Point p(std::atof(av[7]), std::atof(av[8]));

	std::cout << GREEN << "A (" << std::atof(av[1]) <<  " , " << std::atof(av[2]) << ")" << RESET << std::endl;
	std::cout << YELLOW << "B (" << std::atof(av[3]) <<  " , " << std::atof(av[4]) << ")" << RESET << std::endl;
	std::cout << CYAN << "C (" << std::atof(av[5]) <<  " , " << std::atof(av[6]) << ")\n" << RESET << std::endl;
	std::cout << MAGENTA << "P (" << std::atof(av[7]) <<  " , " << std::atof(av[8]) << ")" << RESET << std::endl;


	std::string res = "true";
	std::string color = GREEN;
	if (!bsp(a, b, c, p))
	{
		res = "false";
		color = RED;
	}

	std::cout << BOLD << YELLOW << "Is the point P in ABC?: " << color << res << RESET << std::endl;

	return (0);
}
