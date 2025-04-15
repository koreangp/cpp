/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:26:58 by pscala            #+#    #+#             */
/*   Updated: 2025/02/05 13:59:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << BOLD << "a : " << BLUE << a << RESET << std::endl;
	std::cout << BOLD << "++a : " << BLUE << ++a << RESET << std::endl;
	std::cout << BOLD << "a : " << BLUE << a << RESET << std::endl;
	std::cout << BOLD << "a++ : " << BLUE << a++ << RESET << std::endl;
	std::cout << BOLD << "a : " << BLUE << a << RESET << std::endl;
	std::cout << BOLD << "b : " << RED << b << RESET << std::endl;
	std::cout << BOLD << "b > a: " << RED << b.operator>(a) << RESET << std::endl;
	std::cout << BOLD << "a < b: " << RED << a.operator<(b) << RESET << std::endl;
	std::cout << BOLD << "max between a and b : " << MAGENTA << Fixed::max(a,
		b) << RESET << std::endl;

	Fixed	c(Fixed(4.009f) / Fixed(9.09f));
	std::cout << BOLD << "c : " << GREEN << c << RESET << std::endl;
	std::cout << BOLD << "--c : " << GREEN << --c << RESET << std::endl;
	std::cout << BOLD << "c : " << GREEN << c << RESET << std::endl;
	std::cout << BOLD << "c-- : " << GREEN << c-- << RESET << std::endl;
	std::cout << BOLD << "c == b : " << GREEN << c.operator==(b) << RESET << std::endl;
	std::cout << BOLD << "c != b : " << GREEN << c.operator!=(b) << RESET << std::endl;
	return (0);
}
