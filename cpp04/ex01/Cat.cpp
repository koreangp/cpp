/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:32 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:24:30 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	_Brain = new Brain();
	std::cout << BOLD << YELLOW << "Cat : " << _type << " created!" << RESET << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	_Brain = new Brain(*cpy._Brain);
	std::cout << BOLD << YELLOW << "Cat : " << _type << "copied !" << RESET << std::endl;
}

Cat::~Cat()
{
	delete	_Brain;
	std::cout << BOLD << YELLOW << "Cat" << RED << " destructor called!" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << BOLD << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete _Brain;
		_Brain = new Brain(*src._Brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << BOLD << YELLOW << "Meow!" << RESET << std::endl;
}

std::string Cat::getIdea(const int index)
{
	return (_Brain->getIdea(index));
}

void	Cat::setIdea(const std::string idea, int index)
{
	_Brain->setIdea(idea, index);
}
