/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:15:04 by pscala            #+#    #+#             */
/*   Updated: 2025/04/30 01:26:33 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span test1 = Span(4);

	try
	{
		std::cout << BOLD << GREEN << "TEST 1" << RESET << std::endl;
		test1.addNumber(6);
		test1.addNumber(3);
		test1.addNumber(17);
		test1.addNumber(9);
		test1.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << RESET << '\n';
	}
	
	try
	{
		std::cout << BOLD << YELLOW << "shortest Span : " << test1.shortestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BOLD << BLUE << "longest Span : " << test1.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	std::cout << std::endl;
	Span test2 = Span (2);

	try
	{
		std::cout << BOLD << GREEN << "TEST 2" << RESET << std::endl;
		test2.addNumber(6);
		test2.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BOLD << YELLOW << "shortest Span : " << test2.shortestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BOLD << BLUE << "longest Span : " << test2.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	std::cout << std::endl;

	Span test3(4);
	std::vector<int> v;

	for (int i = 0; i < 100; ++i)
	{
		if (i == 42 || i == 24 || i == 86 || i == 99)
			v.push_back(i);
	}

	try
	{
		std::cout << BOLD << GREEN << "TEST 3" << RESET << std::endl;
		test3.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BOLD << YELLOW << "shortest Span : " << test3.shortestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BOLD << BLUE << "longest Span : " << test3.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}

	return (0);
}
