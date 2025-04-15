/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:21:15 by pscala            #+#    #+#             */
/*   Updated: 2025/01/24 09:15:44 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

void HumanA::attack(void)
{
	std::cout << GREEN << this->name << RESET << BOLD << " attacks with their " << weapon.getType() << RESET << std::endl;
}
