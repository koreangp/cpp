/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:58:18 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:43:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{

	for (int i=0; i < 4; i++)
		_materiaLearned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{

	for (int i = 0; i < 4; i++)
	{
		if (cpy._materiaLearned[i])
			_materiaLearned[i] = cpy._materiaLearned[i]->clone();
		else
			_materiaLearned[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{

	for (int i=0; i < 4; i++)
	{
		if (_materiaLearned[i])
			delete _materiaLearned[i];
	}
	// std::cout << BOLD << RED << "MateriaSource destructor called" << RESET << std::endl;

}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i=0; i < 4; i++)
		{

			if (_materiaLearned[i])
			{
				delete _materiaLearned[i];
				_materiaLearned[i] = NULL;
			}

			_materiaLearned[i] = src._materiaLearned[i]->clone();
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << BOLD << RED << "No Materia to learn" << RESET << std::endl;
		return;
	}

	for (int i=0; i < 4; i++)
	{
		if (_materiaLearned[i] == NULL)
		{
			_materiaLearned[i] = m->clone();

			std::cout << BOLD << YELLOW << "Materia " << m->getType() << " learned !" << RESET << std::endl;
			delete m;
			return;
		}
	}
	std::cout << BOLD << RED << "You cannot learn any new Materia" << RESET << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i=0; i < 4; i++)
	{
		if (_materiaLearned[i] && _materiaLearned[i]->getType() == type)
			return (_materiaLearned[i]->clone());
	}
	std::cout << BOLD << RED << "You cannot creat a Materia you did not learn" << RESET << std::endl;
	return (NULL);
}
