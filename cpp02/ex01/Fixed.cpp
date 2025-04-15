/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:16:31 by pscala            #+#    #+#             */
/*   Updated: 2025/02/02 14:43:00 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
	std::cout << BOLD << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << BOLD << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::Fixed(const int intValue)
{
	std::cout << BOLD << RED << "Int constructor called" << RESET << std::endl;
	this->fixedValue = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << BOLD << RED << "Float constructor called" << RESET << std::endl;
	this->fixedValue = roundf(floatValue * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << BOLD << MAGENTA << "Destructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << BOLD << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->fixedValue = src.fixedValue;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int Fixed::getRawBits() const
{
	std::cout << BOLD << CYAN << "getRawBits member function called" << RESET << std::endl;
	return (fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedValue = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->fixedValue) / (1 << bits));
}

int Fixed::toInt() const
{
	return (static_cast<int>(this->fixedValue) / (1 << bits));
}
