/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:31:31 by pscala            #+#    #+#             */
/*   Updated: 2025/02/12 13:29:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string RESET = "\033[0m";

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << GREEN << "Memory address of the string brain : " << RESET << &brain << std::endl;
	std::cout << YELLOW << "Memory address held by stringPTR : " << RESET << stringPTR << std::endl;
	std::cout << RED << "Memory address held by stringREF : " << RESET << &stringREF << std::endl << std::endl;

	std::cout << GREEN << "Value of the string brain : " << RESET << brain << std::endl;
	std::cout << YELLOW << "Value pointed to by stringPTR : " << RESET << *stringPTR << std::endl;
	std::cout << RED << "Value pointed to by stringREF : " << RESET << stringREF << std::endl;

	return (0);
}
