/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:35:02 by pscala            #+#    #+#             */
/*   Updated: 2025/01/15 12:43:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::display() const
{
	std::cout << BOLD << GREEN << "\nFirst name: " << WHITE << first_name << GREEN
	<< "\nLast name: " << WHITE << last_name << GREEN << "\nNickname: " << WHITE << nickname
	<< GREEN << "\nPhone: " << WHITE << phone_number << GREEN << "\nDarkest secret: "
	<< WHITE << darkest_secret << RESET << std::endl;
}

void Contact::displayContact(int index) const
{
	std::string strIndex;
	std::stringstream ss;

	ss << index;
	strIndex = ss.str();

	if (index % 2 == 0)
	{
		std::cout << BOLD << RED << "|" << WHITE << BG_BRIGHT_BLACK << formatColumn(strIndex, 10) << RESET << BOLD << RED << "|"
        	<< WHITE << BG_BLACK << formatColumn(first_name, 10) << RESET << BOLD << RED << "|"
            << WHITE << BG_BRIGHT_BLACK << formatColumn(last_name, 10) << RESET << BOLD << RED << "|"
            << WHITE << BG_BLACK << formatColumn(nickname, 10) << RESET << BOLD << RED << "|" << RESET << std::endl;
	}
	else
	{
		std::cout << BOLD << RED << "|" << WHITE << BG_BLACK << formatColumn(strIndex, 10) << RESET << BOLD << RED << "|"
        	<< WHITE << BG_BRIGHT_BLACK << formatColumn(first_name, 10) <<  RESET << BOLD << RED << "|"
            << WHITE << BG_BLACK << formatColumn(last_name, 10) <<  RESET << BOLD << RED << "|"
            << WHITE << BG_BRIGHT_BLACK << formatColumn(nickname, 10) << RESET << BOLD << RED << "|" << RESET << std::endl;
	}
}

bool Contact::check_string(std::string string, bool number)
{
	if (string.empty())
		return (false);
	if (number == true)
	{
		if (string.length() != 10)
			return (false);
		for (unsigned long int i = 0; i < string.length(); i++)
		{
			if (!isdigit(string[i]))
				return (false);
			else if (string[0] != '0')
				return (false);
		}
	}
	else
	{
		for (unsigned long int i = 0; i < string.length(); i++)
		{
			if (isdigit(string[i]))
				return (false);
			if (!isalpha(string[i]) && (string[i] != ' '))
				return (false);
		}
	}
	return (true);
}

bool Contact::creat_contact()
{
	while (1)
	{
		std::cout << std::endl << BOLD << BRIGHT_MAGENTA << "Enter the new contact's first name 😇 (only letters and spaces allowed)" << RESET << std::endl;
		std::getline(std::cin >> std::ws, this->first_name);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (!check_string(this->first_name, false))
			std::cout << std::endl << BOLD << RED << "Wrong first name syntax 🙀  Please try again 🐱" << RESET << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << std::endl << BOLD << BRIGHT_MAGENTA << "Enter the new contact's last name 🤗 (only letters and spaces allowed)" << RESET << std::endl;
		std::getline(std::cin >> std::ws, this->last_name);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (!check_string(this->last_name, false))
			std::cout << std::endl << BOLD << RED << "Wrong last name syntax 🙀  Please try again 🐱" << RESET << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << std::endl << BOLD << BRIGHT_MAGENTA << "Enter the new contact's nickname 🥸  (only letters and spaces allowed)" << RESET << std::endl;
		std::getline(std::cin >> std::ws, this->nickname);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (!check_string(this->nickname, false))
			std::cout << std::endl << BOLD << RED << "Wrong nickname syntax 🙀  Please try again 🐱" << RESET << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << std::endl << BOLD << BRIGHT_MAGENTA << "Enter the new contact's phone number 📞 (a valid one starting with 0)" << RESET << std::endl;
		std::getline(std::cin >> std::ws, this->phone_number);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (!check_string(this->phone_number, true))
			std::cout << std::endl << BOLD << RED << "Wrong phone number syntax 🙀  Please try again 🐱" << RESET << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << std::endl << BOLD << BRIGHT_MAGENTA << "Enter the new contact's darkest secret 🐢 (only letters and spaces allowed)" << RESET << std::endl;
		std::getline(std::cin >> std::ws, this->darkest_secret);
		if (std::cin.fail() || std::cin.eof())
			return (false);
		if (!check_string(this->darkest_secret, false))
			std::cout << std::endl << BOLD << RED << "Wrong darkest secret syntax 🙀  Please try again 🐱" << RESET << std::endl;
		else
			break ;
	}
	return (true);
}