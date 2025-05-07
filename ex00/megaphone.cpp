/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:25:20 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 14:42:02 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	capitalize(std::string& s)
{
	int	len = s.length();
	for (int i = 0; i < len; i++)
	{
		s[i] = toupper(s[i]);
	}
}

bool	areAllEmpty(int ac, char **av)
{
	int			i;
	std::string	arg;

	i = 1;
	while (i < ac)
	{
		arg = av[i];
		if (!arg.empty())
			return (false);
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	int	i;
	std::string arg;

	if (ac == 1 || areAllEmpty(ac, av))
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < (ac - 1))
		{
			arg = av[i];
			capitalize(arg);
			if (!arg.empty())
				std::cout << arg << " ";
			i++;
		}
		arg = av[i];
		capitalize(arg);
		std::cout << arg << std::endl;
	}
	return (0);
}
