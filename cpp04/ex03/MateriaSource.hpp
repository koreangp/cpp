/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:57:18 by pscala            #+#    #+#             */
/*   Updated: 2025/03/08 13:01:55 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *_materiaLearned[4];

  public:
	MateriaSource();
	MateriaSource(const MateriaSource &cpy);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &src);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};
