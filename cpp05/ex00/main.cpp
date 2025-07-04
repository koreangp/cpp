/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:33 by pscala            #+#    #+#             */
/*   Updated: 2025/06/08 14:43:02 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << BOLD << GREEN << "test 1:" << std::endl;
		Bureaucrat g("Jojo1", 8);
		std::cout << BOLD << BLUE << g << RESET << std::endl;
		Bureaucrat h("Jojo2", 150);
		std::cout << BOLD << BLUE << h << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << BOLD << GREEN << "test 2:" << std::endl;

		Bureaucrat a("Jojo3", 8);
		std::cout << BOLD << BLUE << a << RESET << std::endl;
		Bureaucrat b("Jojo4", 150);
		std::cout << BOLD << BLUE << b << RESET << std::endl;

		a.decrement();
		std::cout << BOLD << BLUE << a << RESET << std::endl;
		b.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << BOLD << GREEN << "test 3:" << std::endl;

		Bureaucrat g("Jojo5", 0);
		Bureaucrat h("Jojo6", 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << BOLD << GREEN << "test 4:" << std::endl;

		Bureaucrat a("Jojo7", 1);
		Bureaucrat b("Jojo8", 150);
		a.increment();
		b.increment();
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
}
