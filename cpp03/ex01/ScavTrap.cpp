/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:33 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:56:23 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_Name = "Momo";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << BOLD << GREEN << "ScavTrap " << _Name << " created !" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BOLD << BLUE << "ScavTrap " << _Name << " created !" << RESET << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << BOLD << CYAN << "ScavTrap " << _Name << " copied !" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BOLD << RED << "ScavTrap " << _Name << " destroyed !" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << BOLD << YELLOW << "ScavTrap copy assignment operator called" << RESET << std::endl;
	return(*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << BOLD << BLUE << "ScavTrap" << _Name << " is now in gatekeeper mode" << RESET << std::endl;
}
