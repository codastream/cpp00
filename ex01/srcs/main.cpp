/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:01:28 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/17 18:26:09 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

int	main(int ac, char **av)
{
	(void) av;
	std::string command;
	PhoneBook	book;

	if (ac != 1)
	{
		putnl(MSG_ERRARG);
		return (1);
	}
	book = PhoneBook();
	putnl(MSG_COMMAND);
	while (std::getline(std::cin, command) && command.compare("EXIT"))
	{
		if (!command.compare("ADD"))
			tryAddContact(book);
		else if (!command.compare("SEARCH"))
			searchContact(book);
		putnl(MSG_COMMAND);
	}
	return (0);
}
