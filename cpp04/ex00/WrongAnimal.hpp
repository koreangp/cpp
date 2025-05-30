/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:15:17 by pscala            #+#    #+#             */
/*   Updated: 2025/02/19 15:03:15 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Color.hpp"

class WrongAnimal
{
  protected:
	std::string _type;

  public:
	WrongAnimal();
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &src);
	virtual ~WrongAnimal();

	void setType(const std::string type);
	std::string getType() const;
	void makeSound() const;
};
