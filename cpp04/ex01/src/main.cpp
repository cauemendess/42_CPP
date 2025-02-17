#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main()
{
	Animal	*array[10];
	int		i = 0;

	while (i < 5)
		array[i++] = new Dog();
	while (i < 10)
		array[i++] = new Cat();

	array[4]->makeSound();
	array[7]->makeSound();
    std::cout << GREEN << "==============IDEAS===========" << RESET << std::endl;

    std::cout << GREEN << ((Dog *)array[4])->getIdea(4) << RESET << std::endl;
    std::cout << GREEN << ((Dog *)array[7])->getIdea(7) << RESET << std::endl;

	for (i = 0; i < 10; i++)
        delete array[i];
		
	return 0;
}