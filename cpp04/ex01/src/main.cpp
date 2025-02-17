#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main()
{
    Animal a;
	std::cout << a.getType() << std::endl;
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


    std::cout << GREEN << "==============DEEP COPY===========" << RESET << std::endl;
    Cat		cat1;
	std::cout << CYAN << "Cat 1 ideas: " << cat1.getIdea(0) << RESET << std::endl;
	Cat		cat2(cat1);
	std::cout << CYAN << "Cat 2 ideas after copy: " << cat2.getIdea(0) << std::endl;
	std::cout << CYAN << "Changing Cat 1 idea" << std::endl;
	cat1.setIdea(0, "I am a new cat");
	std::cout << CYAN << "Cat 1 ideas: " << cat1.getIdea(0) << RESET << std::endl;
	std::cout << CYAN << "Cat 2 ideas after change in Cat 1: " << cat2.getIdea(0) << RESET << std::endl;

	for (i = 0; i < 10; i++)
        delete array[i];
		
	return 0;
}