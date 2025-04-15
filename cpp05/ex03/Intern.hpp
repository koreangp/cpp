/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:17:48 by pscala            #+#    #+#             */
/*   Updated: 2025/04/14 17:53:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
	AForm *PresidentialForm(const std::string target);
	AForm *RobotForm(const std::string target);
	AForm *ShrubberyForm(const std::string target);

  public:
	Intern();
	Intern(const Intern &cpy);
	~Intern();
	Intern &operator=(const Intern &src);

	AForm *makeForm(const std::string formName, const std::string target);
};
