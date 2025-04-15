/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:44:39 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << BOLD << BLUE << "\n" << "[DEBUG] level: Just a chill debug message" << RESET << std::endl;
}

void Harl::info( void )
{
	std::cout << BOLD << GREEN  << "\n" << "[INFO] level: Just a chill informative message" << RESET << std::endl;
}

void Harl::warning( void )
{
	std::cout << BOLD << YELLOW  << "\n" << "[WARNING] level: Just a not so chill warning message" << RESET << std::endl;
}

void Harl::error( void )
{
	std::cout << BOLD << RED  << "\n" << "[ERROR] level: Just a not chill at all error message" << "\n" << RESET << std::endl;
}

int Harl::complain( std::string level )
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return(i);
		}
	}

	return (-1);
}
