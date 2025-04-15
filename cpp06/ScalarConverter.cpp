/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:52:29 by pscala            #+#    #+#             */
/*   Updated: 2025/04/15 19:59:46 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &str)
{
	std::cout << BOLD << YELLOW << "The string u passed : " << str << RESET << std::endl;

	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		char c = str[0];
		std::cout << BOLD << WHITE << "char: " << GREEN << c << RESET << std::endl;
		std::cout << BOLD << WHITE << "int: " << BLUE << static_cast<int>(c) << RESET << std::endl;
		std::cout << BOLD << WHITE << "float: " << CYAN << static_cast<float>(c) << ".0f" << RESET << std::endl;
		std::cout << BOLD << WHITE << "double: " << MAGENTA << static_cast<double>(c) << ".0" << RESET << std::endl;
		return;
	}

	char *end;
	double value = std::strtod(str.c_str(), &end);

	if (isPseudoLiteral(str))
	{
		std::cout << BOLD << WHITE << "char: " << RED << "impossible" << RESET << std::endl;
		std::cout << BOLD << WHITE << "int: " << RED << "impossible" << RESET << std::endl;
		std::cout << BOLD << WHITE << "float: " << RED << str << RESET << std::endl;
		std::cout << BOLD << WHITE << "double: " << RED << "nan" << RESET << std::endl;
	}

	if (*end != '\0')
	{
		std::cout << BOLD << WHITE << "char: " << RED << "impossible" << RESET << std::endl;
		std::cout << BOLD << WHITE << "int: " << RED << "impossible" << RESET << std::endl;
		std::cout << BOLD << WHITE << "float: " << RED << "nanf" << RESET << std::endl;
		std::cout << BOLD << WHITE << "double: " << RED << "nan" << RESET << std::endl;
	}

	else
	{

	}
}
