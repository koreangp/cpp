/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:24:42 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 01:54:31 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int a = 42;
	int b = 24;
	int c;

	c = ::min(a, b);
	std::cout << BOLD << BLUE << "min of" << " a: " << a << " and b: " << b << " : " << c << std::endl;
	c = ::max(a, b);
	std::cout << BOLD << BLUE << "max of" << " a: " << a << " and b: " << b << " : " << c << std::endl;

	::swap(a, b);
	std::cout << BOLD << BLUE << "a = " << a << "\n" << "b = " << b << std::endl;


	float af = 88.0f;
	float bf = 99.0f;
	float cf;

	cf = ::min(af, bf);
	std::cout << BOLD << MAGENTA << "min of" << " af: " << af << ".0f" << " and bf: " << bf << ".0f" << " : " << cf << ".0f" << std::endl;
	cf = ::max(af, bf);
	std::cout << BOLD << MAGENTA << "max of" << " af: " << af << ".0f" << " and bf: " << bf << ".0f" << " : " << cf << ".0f" << std::endl;

	::swap(af, bf);
	std::cout << BOLD << MAGENTA << "af = " << af << ".0f" << "\n" << "bf = " << bf << ".0f" << std::endl;


	std::string s1 = "JoJo";
	std::string s2 = "Dio";
	std::string s3;

	s3 =::min(s1, s2);
	std::cout << BOLD << YELLOW << "min of" << " s1: " << s1 << " and s2: " << s2 << " : " << s3 << std::endl;
	s3 = ::max(s1, s2);
	std::cout << BOLD << YELLOW << "max of" << " s1: " << s1 << " and s2: " << s2 << " : " << s3 << std::endl;
	::swap(s1, s2);
	std::cout << BOLD << YELLOW << "s1 = " << s1 << "\n" << "s2 = " << s2 << RESET << std::endl;

	return (0);
}
