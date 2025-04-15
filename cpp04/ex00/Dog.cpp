/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:33 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 16:30:18 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << BOLD << BLUE << "Dog : " << _type << " created!" << RESET << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << BOLD << BLUE << "Dog : " << _type << "copied !" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BOLD << BLUE << "Dog" << RED << " destructor called!" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << BOLD << BLUE << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BOLD << BLUE << "Woof! Woof!" << RESET << std::endl;
}
