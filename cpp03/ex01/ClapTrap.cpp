/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:44 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:13:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("JoJo"), _HitPoints(10), _EnergyPoints(10),
	_AttackDamage(0)
{
	std::cout << BOLD << GREEN << "ClapTrap " << _Name << " created !" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10),
	_EnergyPoints(10), _AttackDamage(0)
{
	std::cout << BOLD << BLUE << "ClapTrap " << _Name << " created !" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy) : _Name(copy._Name),
	_HitPoints(copy._HitPoints), _EnergyPoints(copy._EnergyPoints),
	_AttackDamage(copy._AttackDamage)
{
	std::cout << BOLD << CYAN << "ClapTrap " << _Name << " copied !" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD << RED << "ClapTrap " << _Name << " destroyed !" << RESET << std::endl;

}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << BOLD << YELLOW << "ClapTrap copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_Name = src._Name;
		this->_HitPoints = src._HitPoints;
		this->_EnergyPoints = src._EnergyPoints;
		this->_AttackDamage = src._AttackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (_EnergyPoints == 0 || _HitPoints == 0)
	{
		if (_HitPoints == 0)
		{
			std::cout << BOLD << RED << "ClapTrap " << _Name << " has not enough HP to attack !" << RESET << std::endl;
			return;
		}
		else
		{
			std::cout << BOLD << RED << "ClapTrap " <<  _Name << " has not enough Energy Points to attack !" << RESET << std::endl;
			return;
		}
	}
	_EnergyPoints--;
	std::cout << BOLD << MAGENTA << "ClapTrap " << _Name << ": attack " << target << ", causing " << _AttackDamage << " points of damage!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_HitPoints -= amount;
	std::cout << BOLD << YELLOW << "ClapTrap " << _Name << " lose " << amount << " HP ! | HP left : " << _HitPoints << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints == 0 || _HitPoints == 0)
	{
		if (_HitPoints == 0)
		{
			std::cout << BOLD << RED << "ClapTrap " << _Name << " has not enough HP to be repaired !" << RESET << std::endl;
			return;
		}
		else
		{
			std::cout << BOLD << RED << "ClapTrap " << _Name << " has not enough Energy Points to be repaired !" << RESET << std::endl;
			return;
		}
	}
	_EnergyPoints--;
	_HitPoints += amount;
	std::cout << BOLD << GREEN << "ClapTrap " <<  _Name << " Gained " << amount << " back ! | HP left : " << _HitPoints << RESET << std::endl;
}

int	ClapTrap::GetHP()
{
	return (_HitPoints);
}

int ClapTrap::GetEP()
{
	return (_EnergyPoints);
}

int ClapTrap::GetAd()
{
	return (_AttackDamage);
}
