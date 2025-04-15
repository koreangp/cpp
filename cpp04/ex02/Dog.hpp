/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:23 by pscala            #+#    #+#             */
/*   Updated: 2025/02/20 12:25:49 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *_Brain;

  public:
	Dog();
	Dog(const Dog &cpy);
	~Dog();

	Dog &operator=(const Dog &src);
	void makeSound() const;
};
