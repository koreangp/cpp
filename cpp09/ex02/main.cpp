/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:31:21 by pscala            #+#    #+#             */
/*   Updated: 2025/07/08 06:07:41 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	parseArgs(std::string &token)
{
	if (token.empty())
		return (-1);

	char *end;
	long res = std::strtol(token.c_str(), &end, 10);

	if (end[0] != '\0')
		return (-1);

	if (res < 0 || res > INT_MAX)
		return (-1);

	return (static_cast<int>(res));
}


int main(int ac, char **av)
{
	if (ac >= 2)
	{
		std::ostringstream oss;
		for (int i = 1; i < ac; ++i)
			oss << av[i] << " ";

		std::istringstream iss(oss.str());
		std::string token;
		std::vector<int> numbers;

		while (iss >> token)
		{
			int nbr = parseArgs(token);
			if (nbr < 0)
			{
				std::cerr << BRED << "ERROR: Invalid number: " << token << RESET << std::endl;
				return (1);
			}
			std::vector<int>::iterator it = std::find(numbers.begin(), numbers.end(), nbr);

			if (it != numbers.end())
			{
				std::cerr << BRED << "ERROR: Duplicate number found: " << nbr << RESET << std::endl;
				return (1);
			}
			numbers.push_back(nbr);
		}
		PmergeMe doom(numbers);
		doom.sortAndMeasure();

		return (0);
	}
	std::cerr << BRED << "ERROR: Wrong number of arguments" << RESET << std::endl;
	return (1);
}
