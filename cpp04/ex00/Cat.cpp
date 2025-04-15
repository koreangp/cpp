/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:17:32 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 16:30:11 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << BOLD << YELLOW << "Cat : " << _type << " created!" << RESET << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << BOLD << YELLOW << "Cat : " << _type << "copied !" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << BOLD << YELLOW << "Cat" << RED <<" destructor called!" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << BOLD << YELLOW << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << BOLD << YELLOW << "Meow!" << RESET << std::endl;
}
