/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:01:34 by pscala            #+#    #+#             */
/*   Updated: 2025/01/26 14:34:03 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

int	copyAndReplace(std::string search, std::string replace, std::ifstream &infile, std::ofstream &outfile)
{
	std::string line;
	size_t		pos;

	while(std::getline(infile, line))
	{
		pos = line.find(search);
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + replace + line.substr(pos + search.length());
			pos = line.find(search, pos + replace.length());
		}
		outfile << line << std::endl;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << RED << BOLD << "Error : Wrong number of arguments : " << ac - 1 << " out of 3" << RESET << std::endl;
		return (1);
	}
	if (av[2][0] == '\0')
	{
		std::cerr << BOLD << RED << "Error : you are not looking for any string" << RESET << std::endl;
		return (1);
	}

	std::string src = av[1];
	std::string dest = src + ".replace";
	std::string search = av[2];
	std::string replace = av[3];

	std::ifstream infile(src.c_str(), std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << BOLD << RED << "Error : failed to open file : " << src << RESET << std::endl;
		return (1);
	}

	std::ofstream outfile(dest.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cerr << BOLD << RED << "Error : failed to open file : " << dest << RESET << std::endl;
		return (1);
	}
	if (copyAndReplace(search, replace, infile, outfile))
		return (1);
	return (0);
}
