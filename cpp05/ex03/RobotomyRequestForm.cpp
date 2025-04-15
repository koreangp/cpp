/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:15:30 by pscala            #+#    #+#             */
/*   Updated: 2025/04/14 16:32:18 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72,  45), _target("JoJo")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72,  45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << BOLD << BLUE << "*Beep Boop Beep Boop Bzzz*" << RESET << std::endl;

	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << BOLD << GREEN << "target " << BLUE << _target << GREEN
		<< " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << BOLD << RED << "target " << BLUE << _target << RED
		<< " robotomy failed!" << RESET << std::endl;
}
