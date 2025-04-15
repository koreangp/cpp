/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:33 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:24:58 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	_Brain = new Brain();
	std::cout << BOLD << BLUE << "Dog : " << _type << " created!" << RESET << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	_Brain = new Brain(*cpy._Brain);
	std::cout << BOLD << BLUE << "Dog : " << _type << "copied !" << RESET << std::endl;
}

Dog::~Dog()
{
	delete	_Brain;
	std::cout << BOLD << BLUE << "Dog" << RED << " destructor called!" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << BOLD << BLUE << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete _Brain;
		_Brain = new Brain(*src._Brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << BOLD << BLUE << "Woof! Woof!" << RESET << std::endl;
}

std::string Dog::getIdea(const int index)
{
	return (_Brain->getIdea(index));
}

void	Dog::setIdea(const std::string idea, int index)
{
	_Brain->setIdea(idea, index);
}
