/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:36 by pscala            #+#    #+#             */
/*   Updated: 2025/01/21 14:46:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"

class Zombie
{
  private:
	std::string name;

  public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
