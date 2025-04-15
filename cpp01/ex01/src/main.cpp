/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:09 by pscala            #+#    #+#             */
/*   Updated: 2025/01/28 11:00:59 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		nbZb;

	nbZb = 5;
	horde = zombieHorde(nbZb, "JoJo");
	if (!horde)
		return (1);
	for (int i = 0; i < nbZb; i++)
	{
		std::cout << BOLD << GREEN << i + 1 << " " << RESET;
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
