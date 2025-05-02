/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:09 by pscala            #+#    #+#             */
/*   Updated: 2025/05/02 02:08:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class BitcoinExchange
{
  private:
	std::map<std::string, double> _data;

	void parseData(std::string data);
	static bool parseLine(std::istringstream &ss, std::string &date, std::string &btcValue);
	static void trim(std::string &str);
	static bool isValidDate(const std::string &date);
	static bool isValidValue(const std::string &value);
	static bool isStrDigits(const std::string &str);
	static bool isValidYear(const std::string &year, const std::string &month, const std::string &date);


  public:
 	BitcoinExchange();
	BitcoinExchange(const std::string csvFile);
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	double	GetBtcValue(const std::string &date);
	~BitcoinExchange();


};
