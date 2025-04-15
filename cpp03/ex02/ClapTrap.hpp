/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:48 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:13:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class ClapTrap
{
  protected:
	std::string _Name;
	int _HitPoints;
	int _EnergyPoints;
	int _AttackDamage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &copy);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int GetHP();
	int GetEP();
	int	GetAd();
};
