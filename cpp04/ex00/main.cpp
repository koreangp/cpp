/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:53:18 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:50:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*animal = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	const WrongAnimal *wrong = new WrongCat();

	std::cout << "\n" << BOLD << "dog: this is a " << BLUE << dog->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "cat: this is a " << YELLOW << cat->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "animal: this is a " << GREEN << animal->getType() << " " << RESET << std::endl;
	std::cout << BOLD << "wrong: this is a " << MAGENTA << wrong->getType() << " " << RESET << "\n" << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrong->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrong;

	return (0);
}
