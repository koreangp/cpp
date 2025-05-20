/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:05:23 by pscala            #+#    #+#             */
/*   Updated: 2025/05/20 20:16:22 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"


bool isGoodExensionFile(std::string file, std::string extension)
{
	if (file.length() < 4)
		return false;
	return (file.substr(file.length() - 4) == extension);
}

bool parseLine(std::istringstream &ss, std::string &date, std::string &btcValue, char separator, int flag)
{
	if (std::getline(ss, date, separator) && std::getline(ss, btcValue))
	{
		trim(date);
		trim(btcValue);

		if (date.empty() || btcValue.empty())
			return false;


		if (!isValidDate(date))
			return false;

		if (!isValidValue(btcValue, flag))
			return false;

		return true;
	}
	return false;
}

void trim(std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start == std::string::npos)
	{
     	str = "";
		return;
	}

	str = str.substr(start, end - start + 1);
}


bool isValidDate(const std::string &date)
{
	std::string year;
	std::string month;
	std::string day;

	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);

	if (!isStrDigits(year) || !isStrDigits(month) || !isStrDigits(day))
		return false;

	if (!isValidYear(year, month, day))
		return false;

	return true;
}

bool isValidYear(const std::string &year, const std::string &month, const std::string &day)
{
	int intDay = std::atoi(day.c_str());
	int intMonth = std::atoi(month.c_str());
	int intYear = std::atoi(year.c_str());

	if (intYear < 2009 || intYear > 2100)
	{
		std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
		return false;
	}
	if (intYear == 2009)
	{
		if (intMonth < 1)
		{
			std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
			return false;
		}
		if (intMonth == 1 && intDay < 2)
		{
			std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
			return false;
		}
	}

	if (intMonth <= 0 || intMonth > 12)
	{
		std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
		return false;
	}

	if (intDay < 1 || intDay > 31)
	{
		std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
		return false;
	}
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30)
	{
		std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
		return false;
	}

	if (intMonth == 2)
	{
		bool bissextil = (intYear % 4 == 0 && (intYear % 100 != 0 || intYear % 400 == 0));
		if ((bissextil && intDay > 29) || (!bissextil && intDay > 28))
		{
			std::cerr << BOLD << RED << "Error: bad input => " << year << '-' << month << '-' << day << RESET << std::endl;
			return false;
		}
	}
	return true;

}


bool isStrDigits(const std::string &str)
{
	for(size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool isValidValue(const std::string &value, int flag)
{
	char *end;
	double dValue = std::strtod(value.c_str(), &end);

	if (*end != '\0' || value.c_str() == end)
		return false;

	if (dValue < 0)
	{
		if (flag)
			std::cerr << BOLD << RED << "Error: not a positiv number" << RESET << std::endl;
		return false;
	}

	if ((dValue > std::numeric_limits<double>::max() && !flag))
		return false;

	if ((dValue > std::numeric_limits<int>::max() && flag))
	{
		std::cerr << BOLD << RED << "Error: too large number" << RESET << std::endl;
		return false;
	}
	return true;
}
