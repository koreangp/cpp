/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:13:03 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:43:41 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria() : _type("Default Materia")
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
}

AMateria::~AMateria()
{
	// std::cout << BOLD << RED << "AMateria destructor called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	(void) src;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << BOLD << YELLOW << _type << " * use a Materia on " << target.getName() << " *" << RESET << std::endl;
}
