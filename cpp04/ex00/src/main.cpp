#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wrong->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    wrong->makeSound();
    meta->makeSound();


    delete meta;
    delete cat;
    delete dog;
    delete wrong;
    return 0;
}