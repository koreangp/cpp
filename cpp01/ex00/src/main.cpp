/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:06:12 by pscala            #+#    #+#             */
/*   Updated: 2025/01/28 11:05:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Jojo;

	randomChump("Jolyne");
	Jojo = newZombie("JoJo");
	if (!Jojo)
	{
		std::cerr << BOLD << RED << "Error : Allocation failed!" << RESET << std::endl;
		return (1);
	}
	Jojo->announce();
	randomChump("JojoLion");
	delete (Jojo);
}
