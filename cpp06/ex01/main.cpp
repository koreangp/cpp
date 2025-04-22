/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:37:00 by pscala            #+#    #+#             */
/*   Updated: 2025/04/22 18:21:44 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t raw;

	data.name = "JoJo";

	raw = Serializer::serialize(&data);
	std::cout << BOLD << GREEN << "serialized ptr = " << BLUE << raw << RESET << std::endl;
	Data *new_data = Serializer::deserialize(raw);
	std::cout << BOLD << GREEN << "data adresse: " << CYAN << &data << RESET << std::endl;
	std::cout << BOLD << GREEN << "new data adresse: " << CYAN << new_data << RESET << std::endl;

	return(0);
}
