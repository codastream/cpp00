/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ops.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:04 by fpetit            #+#    #+#             */
/*   Updated: 2025/04/27 21:56:05 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"

void	tryAddContact(PhoneBook &book)
{
	Contact		contact;
	std::string	secret;

	contact = Contact();
	putnl("First name ?");
	std::cin >> contact.first_name;
	putnl("Family name ?");
	std::cin >> contact.last_name;
	putnl("Nickname ?");
	std::cin >> contact.nickname;
	putnl("Phone number ?");
	std::cin >> contact.phone_number;
	putnl("Darkest secret ?");
	std::cin >> secret;
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
		std::cin >> index;
		if (!index.compare("BACK"))
			break;
		conv = std::atoi(index.c_str());
		if (conv <= 0 || conv > book.nb_contacts)
			putnl("Incorrect index");
		else
			book.contacts[conv - 1].displayDetailed();
	}

}
