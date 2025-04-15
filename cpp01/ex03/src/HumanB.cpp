/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:21:18 by pscala            #+#    #+#             */
/*   Updated: 2025/01/24 09:57:36 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	this->name = name;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << YELLOW << this->name << RESET << BOLD << " attacks with their " << weapon->getType() << RESET << std::endl;
	else
		std::cout << YELLOW << this->name << RED << BOLD << " has no stand 🧍​ " << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
