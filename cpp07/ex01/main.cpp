/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:03:00 by pscala            #+#    #+#             */
/*   Updated: 2025/04/25 01:58:32 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main()
{
	int intArray [5] = {0, 1, 2, 3, 4};
	iter(intArray, 5, print<int>);

	std::cout << std::endl;
	
	std::string stringArray [] = {"Jojo", "JojoLion", "Joseph"};
	iter(stringArray, 3, print<std::string>);
	return (0);
}
