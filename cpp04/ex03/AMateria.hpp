/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:13:20 by pscala            #+#    #+#             */
/*   Updated: 2025/02/24 14:41:09 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class	ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &copy);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &src);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};


