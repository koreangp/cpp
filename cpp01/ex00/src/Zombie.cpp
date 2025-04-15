/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:06:03 by pscala            #+#    #+#             */
/*   Updated: 2025/01/21 14:46:54 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << BOLD << RED << name << " 🧟" << RESET << BOLD << ": Is purified 🪽" << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << BOLD << YELLOW << name << " 🧟" << RESET << BOLD << ": BraiiiiiiinnnzzzZ...🧠" << RESET << std::endl;
}
