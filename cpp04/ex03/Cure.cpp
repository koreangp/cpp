/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:33:31 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:43:46 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"


Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
}

Cure::~Cure()
{
	// std::cout << BOLD << RED << "Cure destructor called" << RESET << std::endl;

}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << BOLD << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
