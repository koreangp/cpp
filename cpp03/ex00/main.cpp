/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:50:41 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 17:37:20 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jojo;
	ClapTrap jojolion("Jojolion");
	ClapTrap 	josuke = jojolion;

	josuke = jojo;
	int EP = jojolion.GetEP();

	for (int i = 0; i < EP; i++)
	{
		jojolion.attack("Jojo");
		jojo.takeDamage(jojolion.GetAd());
	}

	jojolion.attack("Jojo");
	jojo.beRepaired(100000);

	return (0);
}
