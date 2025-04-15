/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:33 by pscala            #+#    #+#             */
/*   Updated: 2025/04/14 18:55:45 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	AForm *ShrubberyForm = NULL;
	AForm *RobotForm = NULL;
	AForm *PresidentialForm = NULL;
	try
	{
		Bureaucrat JoJo("JoJo", 145);
		std::cout << BOLD << BLUE << JoJo << RESET << std::endl;
		ShrubberyForm = new ShrubberyCreationForm("home");
		RobotForm = new RobotomyRequestForm("Jojo");
		PresidentialForm = new PresidentialPardonForm("Gyro");

		JoJo.signForm(*ShrubberyForm);
		JoJo.executeForm(*ShrubberyForm);

		std::cout << std::endl;

		JoJo.signForm(*RobotForm);
		JoJo.executeForm(*RobotForm);

		std::cout << std::endl;

		JoJo.signForm(*PresidentialForm);
		JoJo.executeForm(*PresidentialForm);

		std::cout << std::endl;

		Bureaucrat JojoLion("JojoLion", 1);
		std::cout << BOLD << BLUE << JojoLion << RESET << std::endl;
		JojoLion.executeForm(*ShrubberyForm);

		std::cout << std::endl;

		JojoLion.signForm(*RobotForm);
		JojoLion.executeForm(*RobotForm);

		std::cout << std::endl;

		JojoLion.signForm(*PresidentialForm);
		JojoLion.executeForm(*PresidentialForm);

	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	delete ShrubberyForm;
	delete RobotForm;
	delete PresidentialForm;
}
