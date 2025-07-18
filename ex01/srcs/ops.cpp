/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:04 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/18 21:25:36 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

bool		isPhoneNumber(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
		{
			return (false);
		}
	}
	return (true);
}

std::string	getNonEmptyField(const std::string& prompt, bool *success)
{
	std::string	input;
	size_t		iStart;

	*success = false;

	putnl(prompt);
	while (std::getline(std::cin, input) && *success == false)
	{
		iStart = input.find_first_not_of(" \t");
		if (iStart == std::string::npos)
		{
			put_red_nl("Please enter a non empty value");
			putnl(prompt);
			input.clear();
		}
		else if (!prompt.compare("Phone number?") && !isPhoneNumber(input))
		{
			put_red_nl("A phone number should be made of digits only");
			putnl(prompt);
			input.clear();
		}
		else if (!input.empty())
		{
			input = input.substr(iStart, input.find_last_not_of(" \t") - iStart + 1);
			*success = true;
			break ;
		}
	}
	return (input);
}

void	refill8Contacts(PhoneBook& book)
{
	for (int i = 1; i <= 8; i++)
	{
		std::ostringstream str;
		Contact contact = Contact();
		str << i;
		contact.setFirstName(str.str());
		contact.setLastName(str.str());
		contact.setNickName(str.str());
		contact.setPhoneNumber(str.str());
		contact.setSecret(str.str());
		book.addContact(contact);
	}
}

void	tryAddContact(PhoneBook& book)
{
	Contact		contact;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	secret;
	bool		success;

	success = false;
	contact = Contact();
	firstName = getNonEmptyField("First name?", &success);
	if (!success)
		return ;
	contact.setFirstName(firstName);
	lastName = getNonEmptyField("Last name?", &success);
	if (!success)
		return ;
	contact.setLastName(lastName);
	nickName = getNonEmptyField("Nickname?", &success);
	if (!success)
		return ;
	contact.setNickName(nickName);
	phoneNumber = getNonEmptyField("Phone number?", &success);
	if (!success)
		return ;
	contact.setPhoneNumber(phoneNumber);
	secret = getNonEmptyField("Secret?", &success);
	if (!success)
		return ;
	contact.setSecret(secret);
	if (contact.isFilledUp() == true)
	{
		book.addContact(contact);
		put_green_nl("Contact has been saved!");
	}
}

/*
Display choices from index 1 to nb_contacts
*/
void	searchContact(PhoneBook &book)
{
	std::string	index;
	int			conv;

	if (book.getNbContacts() == 0)
	{
		put_red_nl("No saved contacts");
		return ;
	}
	book.displayPhonebook();
	putnl("Index of contact to display ? (BACK to come back, FILL for quick fill)");
	while (std::getline(std::cin, index))
	{
		if (index == "BACK")
			break;
		if (index == "FILL")
		{
			refill8Contacts(book);
			break;
		}
		conv = std::atoi(index.c_str());
		if (conv <= 0 || conv > book.getNbContacts())
			put_red_nl("Incorrect index");
		else
			book.getContactByIndex(conv - 1)->displayDetailed();
		putnl("Index of contact to display ? (BACK to come back, , FILL for quick fill)");
	}
}
