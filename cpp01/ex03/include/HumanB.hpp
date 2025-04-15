/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:08 by pscala            #+#    #+#             */
/*   Updated: 2025/01/24 09:53:13 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(std::string name);
	void attack(void);
	void setWeapon(Weapon &weapon);
};
