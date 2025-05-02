/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:46 by pscala            #+#    #+#             */
/*   Updated: 2025/05/02 02:15:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	parseData("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string csvFile)
{
	parseData(csvFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) : _data(cpy._data)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_data = src._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

double	BitcoinExchange::GetBtcValue(const std::string &date)
{
	std::map<std::string, double>::iterator it = _data.upper_bound(date);

	--it;
	return (it->second);
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
		{
			if (_data.find(date) == _data.end())
			{
				double dValue = std::strtod(btcValue.c_str(), NULL);
				_data[date] = dValue;
			}
		}
	}
	if (_data.empty())
		throw std::runtime_error("Error : no data in file");
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

	if (!isValidYear(year, month, day))
		return false;

	return true;
}

bool BitcoinExchange::isValidYear(const std::string &year, const std::string &month, const std::string &day)
{
	int intDay = std::atoi(day.c_str());
	int intMonth = std::atoi(month.c_str());
	int intYear = std::atoi(year.c_str());

	if (intYear < 2009 || intYear > 9999)
		return false;
	if (intYear == 2009)
	{
		if (intMonth < 1)
			return false;
		if (intMonth == 1 && intDay < 2)
			return false;
	}

	if (intMonth <= 0 || intMonth > 12)
		return false;

	if (intDay < 1 || intDay > 31)
		return false;
	if ((intMonth == 4 || intMonth == 6 || intMonth == 9 || intMonth == 11) && intDay > 30)
		return false;
	if (intMonth == 2)
	{
		bool bissextil = (intYear % 4 == 0 && (intYear % 100 != 0 || intYear % 400 == 0));
		if ((bissextil && intDay > 29) || (!bissextil && intDay > 28))
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
	char *end;
	double dValue = std::strtod(value.c_str(), &end);

	if (*end != '\0' || value.c_str() == end)
		return false;

	return true;
}
