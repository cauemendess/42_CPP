#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange exchange (argv);
    }
    catch (std::exception &e)
    {
        std::cout <<  "Error: " << e.what () << std::endl;
    }

    return 0;
}