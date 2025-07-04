/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:53:18 by pscala            #+#    #+#             */
/*   Updated: 2025/05/29 07:37:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal 	*tab[10];
	const Animal	*j = new Dog();
	const Animal	*p = new Dog();
	const Animal	*i = new Cat();

	p = j;
	Dog dog;

	Dog tmp = dog;
	std::cout << "\n" << BOLD << "p: this is a " << BLUE << p->getType() << " " << RESET << std::endl;
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
