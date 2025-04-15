/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:36 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:36:13 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Momo;
	ScavTrap    Momolion("Momolion");
	ScavTrap 	Mosuke = Momolion;

	Mosuke = Momo;
	int EP = Momolion.GetEP();

	for (int i = 0; i < EP; i++)
	{
		Momolion.attack("Momo");
		Momo.takeDamage(Momolion.GetAd());
	}

	Momolion.attack("Momo");
	Momo.beRepaired(100000);

	Momolion.guardGate();
	Momo.guardGate();

	return (0);
}
