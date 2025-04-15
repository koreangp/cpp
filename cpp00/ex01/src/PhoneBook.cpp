/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:34:36 by pscala            #+#    #+#             */
/*   Updated: 2025/01/29 14:38:31 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>


static int	isValidIndex(std::string index, int contactCount)
{
	int	num;

	std::stringstream ss(index);
	if (ss >> num)
	{
		if (num > contactCount || num > 8 || num < 1)
			return (-1);
		return (num);
	}
	else
		return (-1);
}


std::string formatColumn(std::string string, unsigned long int len)
{
	if ((string.length()) > len)
		return (string.substr(0, len - 1) + '.');
	else
		return (std::string(len - string.length(), ' ') + string);
}

PhoneBook::PhoneBook() : contactCount(0), overwrite(0)
{
}

bool PhoneBook::addContact()
{
	if (overwrite >= 8)
		std::cout << std::endl << BOLD << CYAN << "🐘 You will overwrite contact " << ((contactCount % 8) + 1) << " 🐘" << RESET << std::endl;
	if (MyLittlePhoneBook[contactCount % 8].creat_contact())
	{
		overwrite++;
		contactCount++;
		return (true);
	}
	else
		return (false);
}

bool  PhoneBook::searchContact()
{
	int	num;
	std::string index;

	if (contactCount < 1)
	{
		std::cout << std::endl << BOLD << RED << "🐧 No contact found. Please add a contact first using the ADD command. 🐧" << RESET << std::endl;
		return (true);
	}
	else
	{
		std::cout << std::endl << BOLD << RED << "|" << BG_BLACK << WHITE << formatColumn("Index", 10) << RESET << BOLD << RED << "|"
        	<< WHITE << BG_BLACK << formatColumn("First Name", 10) << RESET << BOLD << RED << "|"
        	<< WHITE << BG_BLACK << formatColumn("Last Name", 10) << RESET << BOLD << RED << "|"
        	<< WHITE << BG_BLACK << formatColumn("Nickname", 10) << RESET << BOLD << RED << "|" << std::endl;

		std::cout << "+" << std::string(10, '-') << "+" << std::string(10, '-') << "+"
        	<< std::string(10, '-') << "+" << std::string(10, '-') << "+" << RESET << std::endl;

		for (int i = 0; i < 8 && i < contactCount; i++)
			MyLittlePhoneBook[i].displayContact(i + 1);
	}
	std::cout << std::endl << BOLD << CYAN << "🐬 Enter the index of the contact you're looking for 🐬" << RESET << std::endl;
	while (1)
	{
		std::getline(std::cin, index);
		num = isValidIndex(index, contactCount);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (num >= 0)
		{
			MyLittlePhoneBook[num - 1].display();
			return (true);
		}
		else
			std::cout << std::endl << BOLD << RED << "🦏 Index incorrect. Please enter a correct one. 🦏" << RESET << std::endl;
	}
	return (true);
}
