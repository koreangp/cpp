/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:28:09 by pscala            #+#    #+#             */
/*   Updated: 2025/02/02 14:28:43 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const b(1);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << BOLD << RED << a << RESET << std::endl;
	std::cout << "b is " << BOLD << RED << b << RESET << std::endl;
	std::cout << "c is " << BOLD << RED << c << RESET << std::endl;
	std::cout << "d is " << BOLD << RED << d << RESET << std::endl;
	std::cout << "a is " << BOLD << BLUE << a.toInt() << RESET << " as integer" << std::endl;
	std::cout << "b is " << BOLD << BLUE << b.toInt() << RESET << " as integer" << std::endl;
	std::cout << "c is " << BOLD << BLUE << c.toInt() << RESET << " as integer" << std::endl;
	std::cout << "d is " << BOLD << BLUE << d.toInt() << RESET << " as integer" << std::endl;
	return (0);
}
