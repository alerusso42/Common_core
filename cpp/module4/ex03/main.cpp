/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:30:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

//SECTION subject main
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}

/*SECTION materia not created
int	main()
{
	AMateria* materia;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character();

	materia = src->createMateria("ice");
	me->equip(materia);
	me->use(0, *me);
	delete src;
	delete me;
}
*/

/*SECTION equipping weird stuff
int	main()
{
	AMateria* materia;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character();

	random_seed();
	materia = src->createMateria("MEGA_RAYQUAZA");
	for (int i = 0; i != 123; i++)
		me->equip(materia);
	for (int i = 0; i != 123; i++)
		me->unequip(std::rand());
	for (int i = 0; i != 123; i++)
		me->use(0, *me);
	delete src;
	delete me;
}
*/

/*SECTION learn brainrot materia
int	main()
{
	AMateria* materia;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character();

	random_seed();
	materia = src->createMateria("MEGA_RAYQUAZA");
	materia = src->createMateria("cure");
	materia = src->createMateria("cure");
	materia = src->createMateria("cure");
	materia = src->createMateria("cure");
	materia = src->createMateria("cure");
	for (int i = 0; i != 123; i++)
		src->learnMateria(NULL);
	for (int i = 0; i != 1242; i++)
		src->learnMateria(materia);
	for (int i = 0; i != 1242; i++)
		src->learnMateria(src->createMateria("ice"));
	me->equip(materia);
	delete src;
	delete me;
}
*/

/*SECTION using Character instead of ICharacter
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
Character* me = new Character();
AMateria* tmp;
tmp = src->createMateria("ice");
tmp->use(*me);
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
Character* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
*/
