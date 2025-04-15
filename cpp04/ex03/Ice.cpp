/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:32:42 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:43:50 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
}

Ice::~Ice()
{
	// std::cout << BOLD << RED << "Ice destructor called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BOLD << CYAN << "* shoot an ice bold at " << target.getName() << " *" << RESET << std::endl;
}

