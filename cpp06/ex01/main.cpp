#include <iostream>
#include "Serializer.hpp"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define INVERSE "\033[7m"


void printLine(const std::string& title) {
    std::cout << YELLOW << INVERSE << "-------------------------------------------------" << RESET << std::endl;
    std::cout << YELLOW << INVERSE << title << RESET << std::endl;
    std::cout << YELLOW << INVERSE << "-------------------------------------------------" << RESET << std::endl;
}

int main()
{
    Data* data = new Data;
    data->i = 1;
    data->s = "Hello world!";
    data->f = 3.14f;

    printLine("Data Before Serialization");
    std::cout << BLUE << "Integer: " << data->i << RESET << std::endl;
    std::cout << BLUE << "String: " << data->s << RESET << std::endl;
    std::cout << BLUE << "Float: " << data->f << RESET << std::endl;
    std::cout << BLUE << "Address: " << data << RESET << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    printLine("Data After Serialization");
    std::cout << BLUE << "Raw: " << raw << RESET << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    printLine("Data After Deserialization");
    std::cout << BLUE << "Integer: " << deserializedData->i << RESET << std::endl;
    std::cout << BLUE << "String: " << deserializedData->s << RESET << std::endl;
    std::cout << BLUE << "Float: " << data->f << RESET << std::endl;
    std::cout << BLUE << "Address: " << deserializedData << RESET << std::endl;

    delete data;
    return 0;
}

