/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:06:10 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/12 13:06:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

//	basic test
// int main()
// {
// 	std::srand(random_gen());
// Animal* animal = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// const Dog	* dog = new Dog();
// Dog	* doggone = new Dog();
// dog->abilities().thinking();
// delete j;//should not create a leak
// delete i;
// delete dog;
// delete doggone;
// delete animal;
// return 0;
// }

/*int	main()
{
	Animal* j = new Animal();	//	nothing weird
	Dog		*dog = new Cat();	// does not compile

}*/

#define ANIMAL_NUMBER 8

//subject
// int main()
// {
// 	std::srand(random_gen());
// 	Animal *array[ANIMAL_NUMBER];
// 	for (int32_t i = 0; i < ANIMAL_NUMBER; i++)
// 	{
// 		if (i % 2)
// 			array[i] = new Dog();
// 		else
// 			array[i] = new Cat();
// 	}
// 	for (int32_t i = 0; i < ANIMAL_NUMBER; i++)
// 		delete array[i];
// 	return (0);
// }

//	deep copy test
int	main()
{
	std::srand(random_gen());
	Animal	*ROCKY = new Dog();
	Dog 	Mega_Rayquaza;

	Mega_Rayquaza = *(Dog *)ROCKY;
	delete ROCKY;
	Mega_Rayquaza.makeSound();
	Mega_Rayquaza.abilities().thinking();
}
