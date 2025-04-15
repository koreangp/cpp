/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:17 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 16:06:33 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Color.hpp"

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const std::string type);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &src);
	virtual ~Animal();

	void setType(const std::string type);
	std::string getType() const;
	virtual void makeSound() const;
};
