/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:04 by pscala            #+#    #+#             */
/*   Updated: 2025/02/02 12:36:12 by pscala           ###   ########.fr       */
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

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

	std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
