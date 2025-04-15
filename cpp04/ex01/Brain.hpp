/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:15:21 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:30:33 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Color.hpp"

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &src);
	std::string getIdea(const int index);
	void setIdea(const std::string idea, int index);
};
