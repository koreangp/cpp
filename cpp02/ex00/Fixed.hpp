/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:04 by pscala            #+#    #+#             */
/*   Updated: 2025/01/30 12:11:55 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Fixed
{
	private:
		int	fixedValue;
		static const int floatValue = 8;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed& operator=(const Fixed& src);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
