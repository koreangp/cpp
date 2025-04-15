/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:52:43 by pscala            #+#    #+#             */
/*   Updated: 2024/12/08 18:59:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook NewLittlePhoneBook;
	std::string command;

	std::cout << std::endl << GREEN << BOLD << "🦆 WELCOME TO YOUR LITTLE PHONEBOOK 🦆" << RESET << std::endl << std::endl;
	while (1)
	{
		std::cout << std::endl << YELLOW << BOLD << "🐵 Please enter a command 🐵; ";
		std::cout << "Available commands : " << BLUE << "ADD; " << GREEN << "SEARCH; " << RED << "EXIT; " << RESET << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			if (NewLittlePhoneBook.addContact() == false)
			{
				std::cout << std::endl << std::endl << BOLD << GREEN << "🤫🧏 BYE BYE 🤫🧏" << RESET << std::endl << std::endl;
				break;
			}
		}
		else if (command == "SEARCH")
		{
			if (NewLittlePhoneBook.searchContact() == false)
			{
				std::cout << std::endl << std::endl << BOLD << GREEN << "🤫🧏 BYE BYE 🤫🧏" << RESET << std::endl << std::endl;
				break;
			}
		}
		else if (command == "EXIT" || std::cin.fail() || std::cin.eof())
		{
			std::cout << std::endl << std::endl << BOLD << GREEN << "🤫🧏 BYE BYE 🤫🧏" << RESET << std::endl << std::endl;
			break;
		}
		else 
		{
			std::cout << RED << "🐥 Command " << "\"" << command << "\"" << " not found 🐥" << RESET << std::endl;
		}
	}
	return (0);
}