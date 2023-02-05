/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:45 by keys              #+#    #+#             */
/*   Updated: 2023/02/05 12:29:53 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
