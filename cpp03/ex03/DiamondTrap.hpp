/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:42:48 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 16:33:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string _Name;

  public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &copy);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap &src);
	void attack(const std::string &target);
	void whoAmI();
};
