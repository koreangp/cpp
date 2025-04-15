/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:12:24 by pscala            #+#    #+#             */
/*   Updated: 2025/01/15 13:17:21 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; j < ac; j++)
	{
		for (unsigned long i = 0; i < strlen(av[j]); i++)
			std::cout << static_cast<char>(toupper(av[j][i]));
	}
	std::cout << std::endl;
	return (0);
}
