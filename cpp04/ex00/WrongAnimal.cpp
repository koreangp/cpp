/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:36 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 15:03:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << BOLD << MAGENTA << "Default WrongAnimal : " << _type << " created!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type)
{
	std::cout << BOLD << MAGENTA << "WrongAnimal : " << _type << " created!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	std::cout << BOLD << MAGENTA << "WrongAnimal : " << _type << "copied !" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLD << MAGENTA << "WrongAnimal" << RED <<" destructor called!" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << BOLD << MAGENTA << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		_type = src._type;
	}
	return (*this);
}

void WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << BOLD << MAGENTA << "*WrongAnimal sound*" << RESET << std::endl;
}
