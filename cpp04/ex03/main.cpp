/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:10:15 by pscala            #+#    #+#             */
/*   Updated: 2025/03/13 11:45:59 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter* JoJo = new Character("JoJo");

	AMateria* cure;
	AMateria* ice;
	AMateria* cure2;
	AMateria* ice2;
	AMateria* cure3;

	ice = src->createMateria("ice");
	JoJo->equip(ice);

	cure = src->createMateria("cure");
	JoJo->equip(cure);

	ice2 = src->createMateria("ice");
	JoJo->equip(ice2);

	cure2 = src->createMateria("cure");
	JoJo->equip(cure2);

	ICharacter* bob = new Character("bob");

	for (int i=0; i < 4; i++)
		JoJo->use(i, *bob);

	cure3 = src->createMateria("cure");
	JoJo->equip(cure3);

	for (int i=0; i < 4; i++)
		JoJo->unequip(i);

	JoJo->use(0, *bob);

	JoJo->equip(cure3);
	JoJo->use(0, *bob);
	JoJo->unequip(0);


	delete bob;
	delete JoJo;
	delete src;
	delete ice;
	delete cure;
	delete ice2;
	delete cure2;
	delete cure3;
	return 0;
}
