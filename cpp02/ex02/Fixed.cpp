/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:16:31 by pscala            #+#    #+#             */
/*   Updated: 2025/04/09 15:21:21 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int intValue)
{
	this->fixedValue = intValue << bits;
}

Fixed::Fixed(const float floatValue)
{
	this->fixedValue = roundf(floatValue * 
		(1 << bits));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
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

bool Fixed::operator>(const Fixed &src) const
{
	return (this->fixedValue > src.fixedValue);
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->fixedValue < src.fixedValue);
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->fixedValue >= src.fixedValue);
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->fixedValue <= src.fixedValue);
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->fixedValue == src.fixedValue);
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->fixedValue != src.fixedValue);
}

Fixed Fixed::operator+(const Fixed &src)
{
	Fixed	res;

	res.fixedValue = (this->fixedValue + src.fixedValue);
	return (res);
}

Fixed Fixed::operator-(const Fixed &src)
{
	Fixed	res;

	res.fixedValue = (this->fixedValue - src.fixedValue);
	return (res);
}

Fixed Fixed::operator*(const Fixed &src)
{
	Fixed	res;

	res.fixedValue = ((this->fixedValue) * (src.fixedValue)) >> bits;
	return (res);
}

Fixed Fixed::operator/(const Fixed &src)
{
	Fixed	res;

	if (src.fixedValue == 0)
	{
		std::cerr << RED << BOLD << "Error : divided by 0, value set to default." << RESET << std::endl;
		return (res);
	}
	res.fixedValue = ((this->fixedValue << bits ) / src.fixedValue);
	return (res);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->fixedValue += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->fixedValue -= 1;
	return (temp);
}

Fixed &Fixed::operator++()
{
	this->fixedValue += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->fixedValue -= 1;
	return (*this);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a.fixedValue < b.fixedValue) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a.fixedValue > b.fixedValue) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a.fixedValue < b.fixedValue) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a.fixedValue > b.fixedValue) ? a : b);
}
