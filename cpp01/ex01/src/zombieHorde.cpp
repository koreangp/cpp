/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:19 by pscala            #+#    #+#             */
/*   Updated: 2025/01/28 11:02:19 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if ((N < 1) || (N > 500000))
	{
		std::cerr << BOLD << RED << "Error : Invalid number of zombies : " << N <<  RESET << std::endl;
		return (NULL);
	}

	Zombie	*horde;
	horde = new Zombie[N];
	if (!horde)
	{
		std::cerr << BOLD << RED << "Error : Allocation failed!" << RESET << std::endl;
		return (NULL);
	}

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}
