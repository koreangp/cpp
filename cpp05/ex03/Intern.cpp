/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:17:26 by pscala            #+#    #+#             */
/*   Updated: 2025/04/14 18:54:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &cpy)
{
	(void) cpy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return (*this);
}

AForm *Intern::PresidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::RobotForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::ShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string index[3] = {"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	AForm *(Intern::*functions[])(const std::string target) = {
		&Intern::ShrubberyForm,
		&Intern::RobotForm,
		&Intern::PresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (index[i] == formName)
		{
			std::cout << BOLD << MAGENTA << "Intern creates " << YELLOW
			<< formName << RESET << std::endl;
			return ((this->*functions[i])(target));
		}
	}
	std::cerr << BOLD << RED << "provided form name : " << YELLOW
	<< formName << " does not exist" << std::endl;
	return (NULL);
}
