/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:04 by pscala            #+#    #+#             */
/*   Updated: 2025/02/04 11:24:15 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Fixed
{
  private:
	int fixedValue;
	static const int bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int intValue);
	Fixed(const float floatValue);
	~Fixed();

	Fixed &operator=(const Fixed &src);
	bool operator>(const Fixed &src) const;
	bool operator<(const Fixed &src) const;
	bool operator>=(const Fixed &src) const;
	bool operator<=(const Fixed &src) const;
	bool operator==(const Fixed &src) const;
	bool operator!=(const Fixed &src) const;

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++();
	Fixed &operator--();

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
