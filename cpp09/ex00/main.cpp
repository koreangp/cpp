/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:51:34 by pscala            #+#    #+#             */
/*   Updated: 2025/07/04 23:00:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BtcExchange(std::string txt, BitcoinExchange exchange)
{
	if (!isGoodExensionFile(txt, ".txt"))
		throw std::runtime_error("Error : Wrong file extension");

	std::string line;
	std::ifstream file(txt.c_str());

	if (!file)
		throw std::runtime_error("Error : could not open file");

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, btcQuant;

		if (parseLine(ss, date, btcQuant, '|', 1))
		{
			char *end;
			double Quant = std::strtod(btcQuant.c_str(), &end);

			std::cout << BOLD << BLUE << date << MAGENTA << " => " << YELLOW << (exchange.GetBtcValue(date) * Quant) << RESET << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange test;

			BtcExchange(av[1], test);
			return (0);
		}

		catch(const std::exception& e)
		{
			std::cerr << BOLD << RED << e.what() << '\n' << RESET;
			return (1);
		}
	}
	std::cerr << BOLD << RED << "Error: wrong number of arguments." << RESET << std::endl;
	return (1);
}
