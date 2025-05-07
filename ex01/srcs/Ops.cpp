/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ops.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:04 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 16:06:33 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"

std::string	getNonEmptyField(const std::string& prompt)
{
	std::string	input;
	size_t		iStart;

	do
	{
		putnl(prompt);
		std::getline(std::cin, input);
		iStart = input.find_first_not_of(" \t");
		if (iStart == std::string::npos)
		{
			putnl("Please enter a value");
			input.clear();
		}
		else
		{
			input = input.substr(iStart, input.find_last_not_of(" \t") - iStart + 1);
		}
	} while (input.empty());
	return (input);
}

void	tryAddContact(PhoneBook &book)
{
	Contact		contact;
	std::string	secret;

	contact = Contact();
	contact.first_name = getNonEmptyField("First name?");
	contact.last_name = getNonEmptyField("Last name?");
	contact.nickname = getNonEmptyField("Nickname?");
	contact.phone_number = getNonEmptyField("Phone number?");
	secret = getNonEmptyField("Secret?");
	contact.setSecret(secret);
	if (contact.isFilledUp() == true)
	{
		book.addContact(contact);
	}
}

/*
Display choices from index 1 to nb_contacts
*/
void	searchContact(PhoneBook &book)
{
	std::string	index;
	int			conv;
	bool		shouldReprompt;

	if (book.nb_contacts == 0)
	{
		putnl("No saved contacts");
		return ;
	}
	book.displayPhonebook();
	shouldReprompt = true;
	while (shouldReprompt)
	{
		putnl("Index of contact to display ? (BACK to come back)");
		std::getline(std::cin, index);
		if (!index.compare("BACK"))
			break;
		conv = std::atoi(index.c_str());
		if (conv <= 0 || conv > book.nb_contacts)
			putnl("Incorrect index");
		else
			book.contacts[conv - 1].displayDetailed();
	}

}
