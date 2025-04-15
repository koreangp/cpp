/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:15:50 by pscala            #+#    #+#             */
/*   Updated: 2025/04/13 18:32:39 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145,  137), _target("home")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145,  137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << BOLD << RED << "Error: Could not creat the file " << _target << RESET << std::endl;
		return;
	}
	 file << ".     .  .      +     .      .          .\n";
	 file << ".       .      .    \"#\"       .           .\n";
	 file << "   .      .        \"###\"            .      .      .\n";
	 file << " .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
	 file << "	 .      . 	\"####\"###\"####\"  .\n";
	 file << "  .  	  \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
 	 file << ".         \"#########\"#########\"        .        .\n";
	 file << "   .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
	 file << ".     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
	 file << "		   		.\"##\"#####\"#####\"##\"           .      .\n";
   	 file << ".  \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
	 file << " .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
   	 file << ".    .     \"#####\"\"#######\"\"#####\"    .      .\n";
	 file << "	   .     \"       .000      \"    .     .\n";
	 file << "  .         .   .   000     .        .       .\n";
	 file << ".. .. .............O000O........................ ......\n";
	file.close();
}
