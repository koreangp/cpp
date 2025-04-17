/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:52:29 by pscala            #+#    #+#             */
/*   Updated: 2025/04/17 14:24:25 by pscala           ###   ########.fr       */
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

		if ((std::isprint(static_cast<int>(c))))
			std::cout << BOLD << WHITE << "1char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << BOLD << WHITE << "2char: '" << GREEN << static_cast<char>(c) << WHITE << "'" << RESET << std::endl;
		std::cout << BOLD << WHITE << "int: " << BLUE << static_cast<int>(c) << RESET << std::endl;
		std::cout << BOLD << WHITE << "float: " << CYAN << static_cast<float>(c) << ".0f" << RESET << std::endl;
		std::cout << BOLD << WHITE << "double: " << MAGENTA << static_cast<double>(c) << ".0" << RESET << std::endl;
		return;
	}

	char *end;
	double value = std::strtod(str.c_str(), &end);


		if (*end != '\0' && *end == 'f' && strlen(end) != 1)
		{

			std::cout << BOLD << WHITE << "4char: " << RED << "impossible" << RESET << std::endl;
			std::cout << BOLD << WHITE << "int: " << RED << "impossible" << RESET << std::endl;
			std::cout << BOLD << WHITE << "float: " << RED << "impossible" << RESET << std::endl;
			std::cout << BOLD << WHITE << "double: " << RED << "impossible" << RESET << std::endl;
			return;
		}

			if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
				std::cout << BOLD << WHITE  << "char11: " << RED << "impossible" << RESET << std::endl;
			else if (!std::isprint(static_cast<int>(value)) || value < 0)
				std::cout << BOLD << WHITE << "char: " << RED << "Non displayable" << RESET << std::endl;
			else
				std::cout << BOLD << WHITE << "6char: '" << GREEN << static_cast<char>(value) << WHITE << "'" << RESET << std::endl;

			if (value > 2147483647 || value < -2147483648 || std::isnan(value))
				std::cout << BOLD << WHITE << "int: " << RED << " impossible" << RESET << std::endl;
			else
				std::cout << BOLD << WHITE << "int: " << BLUE << static_cast<int>(value) << RESET << std::endl;

			if (std::isnan(value) || std::isinf(static_cast<float>(value)))
				std::cout << BOLD << WHITE << "f111loat: " << CYAN <<  static_cast<float>(value) << "f" << RESET << std::endl;
			else
				std::cout << BOLD << WHITE << "11float: " << CYAN << static_cast<float>(value) << ".0f" << RESET << std::endl;

			if (std::isnan(value) || std::isinf(value))
				std::cout << BOLD << WHITE << "double: " << MAGENTA << value << RESET << std::endl;
			else
				std::cout << BOLD << WHITE << "double: " << MAGENTA << value << ".0" << RESET << std::endl;
			return;

}
