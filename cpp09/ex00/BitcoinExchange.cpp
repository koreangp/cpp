/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:46 by pscala            #+#    #+#             */
/*   Updated: 2025/05/20 20:16:55 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	parseData("data.csv");
	// printDatabase();

}

BitcoinExchange::BitcoinExchange(const std::string csvFile)
{
	parseData(csvFile);
	// printDatabase();

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

	if (it == _data.begin())
		throw std::runtime_error("No data before this date");

	--it;
	return (it->second);
}

void BitcoinExchange::printDatabase() const
{
	if (_data.empty())
	{
		std::cout << BOLD << RED << "data base is empty" << std::endl;
		return;
	}

	std::cout << BOLD << GREEN << "=== Contenu de la base de données ===" << std::endl;
	for (std::map<std::string, double>::const_iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

void BitcoinExchange::parseData(std::string src)
{
	if (!isGoodExensionFile(src, ".csv"))
		throw std::runtime_error("Error : Wrong file extension");

	std::string line;
	std::ifstream file(src.c_str());

	if (!file)
		throw std::runtime_error("Error : cant open file");

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, btcValue;

		if (parseLine(ss, date, btcValue, ',', 0))
		{
			if (_data.find(date) == _data.end())
			{
				double dValue = std::strtod(btcValue.c_str(), NULL);
				_data[date] = dValue;
			}
		}
	}
	if (_data.empty())
		throw std::runtime_error("Error : no _data in file");
}



