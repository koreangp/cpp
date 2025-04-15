/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:20 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 10:31:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *_Brain;

  public:
	Cat();
	Cat(const Cat &cpy);
	~Cat();

	Cat &operator=(const Cat &src);
	void makeSound() const;
	std::string getIdea(const int value);
	void setIdea(const std::string idea, int value);
};
