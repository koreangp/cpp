/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:16:31 by pscala            #+#    #+#             */
/*   Updated: 2025/01/30 13:43:12 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
	std::cout << BOLD << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << BOLD << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = src;
}



Fixed::~Fixed()
{
	std::cout << BOLD << MAGENTA << "Destructor called" << RESET << std::endl;

}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << BOLD << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->fixedValue = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << BOLD << CYAN << "getRawBits member function called" << RESET << std::endl;
	return (fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	fixedValue = raw;
}
