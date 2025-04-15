/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:36 by pscala            #+#    #+#             */
/*   Updated: 2025/02/12 12:41:03 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Diamond;
	DiamondTrap    Josuke("Josuke");
	DiamondTrap 	Jonathan = Josuke;

	Jonathan = Diamond;
	int EP = Josuke.GetEP();

	std::cout << BOLD << RED << "JOSUKE EP : " << EP << std::endl;
	for (int i = 0; i < EP; i++)
	{
		Josuke.attack("Diamond");
		Diamond.takeDamage(Josuke.GetAd());
	}

	Josuke.attack("Diamond");
	Diamond.beRepaired(100000);

	Josuke.guardGate();
	Diamond.guardGate();

	Josuke.highFivesGuys();
	Diamond.highFivesGuys();

	Josuke.whoAmI();
	Diamond.whoAmI();

	return (0);
}
