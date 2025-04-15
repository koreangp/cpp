/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:15 by pscala            #+#    #+#             */
/*   Updated: 2025/01/28 10:56:47 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"

class Zombie
{
  private:
	static int deathCount;
	std::string name;

  public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void setName(std::string &newName);
	void incrementDeathCount();
};

Zombie	*zombieHorde(int N, std::string name);
