/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:46:32 by pscala            #+#    #+#             */
/*   Updated: 2025/02/28 16:22:11 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
	AMateria *_inventory[4];
	std::string _name;

  public:
	Character();
	Character(const std::string name);
	Character(const Character &cpy);
	~Character();

	Character &operator=(const Character &src);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
