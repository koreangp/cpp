/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:46:12 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:43:36 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Jojo")
{
	for (int i=0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string name) : _name(name)
{
	for (int i=0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &cpy) : _name(cpy._name)
{
	for (int i=0; i < 4; i++)
	{
		if (cpy._inventory[i])
			_inventory[i] = cpy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
	// std::cout << BOLD << RED << "Character destructor called" << RESET << std::endl;

}


Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		for (int i=0; i < 4; i++)
		{

			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}

			_inventory[i] = src._inventory[i]->clone();
		}
	}
	_name = src._name;
	return (*this);
}


void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << BOLD << "Nothing to equip" << RESET << std::endl;
		return;
	}

	for (int i=0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			std::cout << BOLD << RED << "Materia " << m->getType() << "is already in your inventory" << RESET << std::endl;
			return;
		}
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << BOLD << "Equiped " << m->getType() << " Materia" << RESET << std::endl;
			return;
		}
	}
	std::cout << BOLD << RED << "Iventory is full, Materia " << m->getType() << " not equiped" << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if ((idx >= 0 && idx < 4 && _inventory[idx] != NULL))
	{
		std::cout << BOLD << MAGENTA << "Materia " << _inventory[idx]->getType() << " unequiped" << RESET << std::endl;
		_inventory[idx] = NULL;
		return;
	}
	std::cout << BOLD << RED << "Iventory : " << idx << " nothing to unequip" << RESET << std::endl;

}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (!_inventory[idx])
		{
			std::cout << BOLD << RED << "No Materia in this index" << RESET << std::endl;
			return;
		}
		_inventory[idx]->use(target);
		return;
	}
	std::cout << BOLD << RED << "Wrong Materia index" << RESET << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}
