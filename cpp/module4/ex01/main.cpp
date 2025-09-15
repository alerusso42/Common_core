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

//	subject
int main()
{
Animal* animal = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const Dog	* dog = new Dog();
Dog	* doggone = new Dog();
dog->abilities().thinking();
delete j;//should not create a leak
delete i;
delete dog;
delete doggone;
delete animal;
return 0;
}

/*int	main()
{
	Animal* j = new Animal();	//	nothing weird
	Dog		*dog = new Cat();	// does not compile

}*/



