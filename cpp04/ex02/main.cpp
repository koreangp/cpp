/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:53:18 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:48:08 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal 	*tab[10];
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "\n" << BOLD << "j: this is a " << BLUE << j->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "i: this is a " << YELLOW << i->getType() << " " << RESET << std::endl;

	j->makeSound();
	i->makeSound();

	std::cout << std::endl;

	for (int k=0; k < 10; k++)
	{
		if (k < 5)
			tab[k] = new Dog;
		else
			tab[k] = new Cat;
	}

	std::cout << std::endl;

	for (int k=0; k < 10; k++)
	{
		tab[k]->makeSound();
	}

	std::cout << std::endl;

	delete			i;
	delete			j;

	for (int k=0; k < 10; k++)
	{
		delete tab[k];
	}
	return (0);
}
