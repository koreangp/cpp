/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:09 by pscala            #+#    #+#             */
/*   Updated: 2025/05/20 19:20:24 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parsing.hpp"

class BitcoinExchange
{
  private:
	std::map<std::string, double> _data;

	void parseData(std::string src);
	void printDatabase() const;

  public:
 	BitcoinExchange();
	BitcoinExchange(const std::string csvFile);
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	double	GetBtcValue(const std::string &date);

};
