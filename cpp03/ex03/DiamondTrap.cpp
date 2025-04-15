/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:41:23 by pscala            #+#    #+#             */
/*   Updated: 2025/02/12 12:04:24 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _Name("DiamondIsUnbreakable")
{
	ClapTrap::_Name = "DiamondIsUnbreakable_clap_name";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << BOLD << BLUE << "DiamondTrap default constructor called : " << this->_Name << " created !" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _Name(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << BOLD << CYAN << "DiamondTrap surcharged constructor called : " << this->_Name << " created !" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _Name(copy._Name)
{
	std::cout << BOLD << CYAN << "DiamondTrap copy constructor called : " << this->_Name << " copied !" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD << RED << "DiamondTrap " << this->_Name<< ": destroyed !" << RESET << std::endl;
}


DiamondTrap &DiamondTrap::operator=(DiamondTrap &src)
{
	ClapTrap::operator=(src);
	ScavTrap::operator=(src);
	FragTrap::operator=(src);
	this->_Name = src._Name;
	std::cout << BOLD << YELLOW << "DiamondTrap : copy assignment operator called" << RESET << std::endl;
	return(*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << BOLD << YELLOW << "Diamontrap " << _Name << ": my name is " << this->_Name << " | My ClapTrap name is " << ClapTrap::_Name << RESET << std::endl;

}
