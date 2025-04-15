/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:33 by pscala            #+#    #+#             */
/*   Updated: 2025/04/12 19:27:01 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat g("Jojo1", 8);
		std::cout << BOLD << BLUE << g << RESET << std::endl;
		Bureaucrat h("Jojo2", 151);
		std::cout << BOLD << BLUE << h << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		Bureaucrat a("Jojo3", 8);
		Bureaucrat b("Jojo4", 150);
		a.decrement();
		b.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		Bureaucrat g("Jojo5", 0);
		Bureaucrat h("Jojo6", 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
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
