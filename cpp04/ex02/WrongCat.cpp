/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:32 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 15:04:44 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << BOLD << MAGENTA << "Default WrongCat : " << _type << " created!" << RESET << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << BOLD << MAGENTA << "WrongCat : " << _type << " created!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << BOLD << MAGENTA << "WrongCat : " << _type << "copied !" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BOLD << MAGENTA << "WrongCat" << RED <<" destructor called!" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << BOLD << MAGENTA << "WrongCat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << BOLD << MAGENTA << "Meow!" << RESET << std::endl;
}
