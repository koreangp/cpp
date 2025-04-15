/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:12 by pscala            #+#    #+#             */
/*   Updated: 2025/01/28 10:55:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::deathCount = 1;

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << BOLD << BLUE << deathCount << RED << " " << name << " 🧟" << RESET << BOLD << ": Is purified 🪽" << RESET << std::endl;
	incrementDeathCount();
}

void Zombie::announce(void)
{
	std::cout << BOLD << YELLOW << name << " 🧟" << RESET << BOLD << ": BraiiiiiiinnnzzzZ...🧠" << RESET << std::endl;
}

void Zombie::setName(std::string &newName)
{
	this->name = newName;
}

void Zombie::incrementDeathCount()
{
	deathCount++;
}
