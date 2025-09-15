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
random_seed();
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
const Dog	* dog = new Dog();
Dog	* doggone = new Dog();
dog->abilities().thinking();
delete j;//should not create a leak
delete i;
delete dog;
delete doggone;
return 0;
}

/*int	main()
{
	AAnimal* j = new AAnimal();	//	nothing weird
	Dog		*dog = new Cat();	// does not compile

}*/



