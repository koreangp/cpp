/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:33 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:56:53 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_Name = "Toto";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << BOLD << GREEN << "FragTrap default constructor called : " << _Name << " created !" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << BOLD << BLUE << "FragTrap surcharged constructor called :" << _Name << " created !" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	std::cout << BOLD << CYAN << "FragTrap " << _Name << ": copied !" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BOLD << RED << "FragTrap " << _Name << ": destroyed !" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << BOLD << YELLOW << "FragTrap : copy assignment operator called" << RESET << std::endl;
	return(*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << BOLD << BLUE << "FragTrap " << _Name << ": Give me a high five! ✋" << RESET << std::endl;
}
