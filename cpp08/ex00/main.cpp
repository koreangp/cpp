/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:20:56 by pscala            #+#    #+#             */
/*   Updated: 2025/04/26 18:13:43 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 3; i++)
		v.push_back(i);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << BOLD << YELLOW << "Occurence found: " << *it << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}


	std::list<int> list;

	for (int i = 0; i < 3; i++)
		list.push_back(i);

	try
	{
		std::list<int>::iterator it = easyfind(list, 2);
		std::cout << BOLD << GREEN << "Occurence found: " << *it << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}


	std::deque<int> doubleEndedQueue;

	for (int i = 0; i < 5; i++)
		doubleEndedQueue.push_front(i);

	try
	{
		std::deque<int>::iterator it = easyfind(doubleEndedQueue, 0);
		std::cout << BOLD << BLUE << "Occurence found: " << *it << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n' << RESET;
	}
	return (0);
}
