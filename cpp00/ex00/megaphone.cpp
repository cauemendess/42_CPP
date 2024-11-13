#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string text = argv[i];
		for (size_t size = 0; size < text.length(); size++)
			text[size] = (char)std::toupper(text[size]);
		std::cout << text;
		std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}
