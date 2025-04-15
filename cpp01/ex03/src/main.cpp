/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:21:20 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 13:04:03 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{

	Weapon stand = Weapon("stand : Star platinium!");
	HumanA Jotaro("Jotaro", stand);
	Jotaro.attack();
	stand.setType("stand : Star planium THE WORLD!");
	Jotaro.attack();

	Weapon stando = Weapon("stand : THE WORLD!");
	HumanB dio("Dio");
	dio.attack();
	dio.setWeapon(stando);
	dio.attack();
	stando.setType("stand : Made in Heaven!");
	dio.attack();
	return (0);
}
