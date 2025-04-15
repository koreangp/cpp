/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:36 by pscala            #+#    #+#             */
/*   Updated: 2025/02/20 12:43:01 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << BOLD << GREEN << "Animal : " << _type << " created!" << RESET << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
	std::cout << BOLD << GREEN << "Animal : " << _type << " created!" << RESET << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << BOLD << GREEN << "Animal : " << _type << "copied !" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BOLD << GREEN << "Animal" << RED <<" destructor called!" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << BOLD << GREEN << "Animal copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		_type = src._type;
	}
	return (*this);
}

void Animal::setType(std::string type)
{
	_type = type;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << BOLD << GREEN << "*Animal sound*" << RESET << std::endl;
}
