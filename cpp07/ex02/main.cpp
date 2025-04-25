/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:42:04 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 06:17:51 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>


#define MAX_VAL 750

int	main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	try
	{
		std::cout << BOLD << GREEN << "test 1 : index = -2" << RESET << std::endl;
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << std::endl;
	}
	try
	{
		std::cout << BOLD << GREEN << "test 2 : index = MAX_VAL" << RESET << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror;
	return (0);
}
