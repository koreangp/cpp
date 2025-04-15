/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:59:11 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 10:37:00 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << BOLD << BLUE << "[DEBUG] level: Just a chill debug message" << RESET << std::endl;
}

void Harl::info( void )
{
	std::cout << BOLD << GREEN << "[INFO] level: Just a chill informative message" << RESET << std::endl;
}

void Harl::warning( void )
{
	std::cout << BOLD << YELLOW << "[WARNING] level: Just a not so chill warning message" << RESET << std::endl;
}

void Harl::error( void )
{
	std::cout << BOLD << RED << "[ERROR] level: Just a not chill at all error message" << RESET << std::endl;
}

void Harl::complain( std::string level )
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	
	std::cout << BOLD << MAGENTA << "[Unknown] level: " << level << RESET << std::endl;
}
