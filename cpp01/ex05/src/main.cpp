/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:59:14 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 10:39:07 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main()
{
	Harl Chill;

	std::cout << std::endl;
	Chill.complain("DEBUG");
	Chill.complain("INFO");
	Chill.complain("WARNING");
	Chill.complain("ERROR");
	Chill.complain("APOCALYPSE");
	std::cout << std::endl;

	return (0);
}
