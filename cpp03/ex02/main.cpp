/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:36 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:33:51 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Toto;
	FragTrap    Totolion("Totolion");
	FragTrap 	Tosuke = Totolion;

	Tosuke = Toto;
	int EP = Totolion.GetEP();
	for (int i = 0; i < EP; i++)
	{
		Totolion.attack("Toto");
		Toto.takeDamage(Totolion.GetAd());
	}

	Totolion.attack("Toto");
	Toto.beRepaired(100000);

	Totolion.highFivesGuys();
	Toto.highFivesGuys();

	return (0);
}
