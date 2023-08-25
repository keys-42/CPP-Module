#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	int		k;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
		{
			c = toupper(argv[i][k]);
			std::cout << c;
			k++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
