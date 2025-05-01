/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:46 by pscala            #+#    #+#             */
/*   Updated: 2025/05/01 05:35:53 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	parseData("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string csvFile)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{

}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::parseData(std::string data)
{
	std::ifstream file(data);
	std::string line;

	if (!file)
		throw std::runtime_error("Error : unknown file");

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, btcValue;

		if (parseLine(ss, date, btcValue))
			//ajouter la key et la value a ma map
			;
	}
}

bool BitcoinExchange::parseLine(std::istringstream &ss, std::string &date, std::string &btcValue)
{
	if (getline(ss, date, ',') && std::getline(ss, btcValue))
	{
		trim(date);
		trim(btcValue);

		if (date.empty() || btcValue.empty())
			return false;

		if (!isValidDate(date))
			return false;

		if (!isValidValue(btcValue))
			return false;

		return true;
	}
	return false;
}

void BitcoinExchange::trim(std::string &str)
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


bool BitcoinExchange::isValidDate(const std::string &date)
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

	if (!isValidYear(year) || !isValidMonth(month) || !isValidDay(day, month, year))
		return false;
}

bool BitcoinExchange::isValidYear(const std::string &year)
{
	int intYear = std::atoi(year.c_str());

	if (intYear > 9999)
		return false;

	return true;
}

bool BitcoinExchange::isValidMonth(const std::string &month)
{
	int intMonth = std::atoi(month.c_str());

	if (intMonth <= 0 || intMonth > 12)
		return false;

	return true;

}

bool BitcoinExchange::isValidDay(const std::string &day, const std::string &month, const std::string &year)
{
	int intDay = std::atoi(day.c_str());
	int intMonth = std::atoi(month.c_str());
	int intYear = std::atoi(year.c_str());


	if (intDay < 1 || intDay > 31)
		return false;
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30)
		return false;
	if (intMonth == 2)
	{
		bool isLeap = (intYear % 4 == 0 && (intYear % 100 != 0 || intYear % 400 == 0));
		if ((isLeap && intDay > 29) || (!isLeap && intDay > 28))
			return false;
	}

	return true;
}

bool BitcoinExchange::isStrDigits(const std::string &str)
{
	for(size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{

}
