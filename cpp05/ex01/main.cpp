/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:33 by pscala            #+#    #+#             */
/*   Updated: 2025/04/13 16:04:03 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat g("Jojo1", 1);
		std::cout << BOLD << BLUE << g << std::endl;
		Form A("FormA", 9, 9);
		std::cout << BOLD << YELLOW << A << std::endl;
		g.signForm(A);
		std::cout << std::endl;
		std::cout << BOLD << YELLOW << A << std::endl;

		std::cout << std::endl;

		Bureaucrat h("Jojo150", 150);
		std::cout << BOLD << BLUE << h << std::endl;
		Form B("FormB", 9, 9);
		std::cout << BOLD << YELLOW << B << std::endl;
		h.signForm(B);
		std::cout << std::endl;
		std::cout << BOLD << YELLOW << B << std::endl;

		for (int i = 0; i < 149; i++)
		{
			h.increment();
		}
		std::cout << std::endl;
		std::cout << BOLD << BLUE << h << std::endl;
		h.signForm(B);
		std::cout << std::endl;
		std::cout << BOLD << YELLOW << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
}
