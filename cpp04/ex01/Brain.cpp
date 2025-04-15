/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:15:34 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:23:11 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i=0; i < 100; i++)
	{
		ideas[i] = "";
	}
	std::cout << BOLD << MAGENTA << "Brain created !" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << BOLD << YELLOW << "Brain copied !" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = copy.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << BOLD << RED << "Brain destroyed !" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = src.ideas[i];
		}
	}
	return (*this);
}

std::string Brain::getIdea(int index)
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "ERROR : Not a good index";
}

void	Brain::setIdea(const std::string idea, int index)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
		return;
	}
	std::cout << BOLD << RED << "ERROR : " << index << " Not a good index" << RESET << std::endl;
}

