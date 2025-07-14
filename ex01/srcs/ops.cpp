/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:04 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/14 13:33:50 by fpetit           ###   ########.fr       */
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
	while (std::getline(std::cin, input))
	{
		iStart = input.find_first_not_of(" \t");
		if (iStart == std::string::npos)
		{
			put_red_nl("Please enter a non empty value");
			input.clear();
			return ("");
		}
		else if (!prompt.compare("Phone number?") && !isPhoneNumber(input))
		{
			put_red_nl("A phone number should be made of digits only");
			input.clear();
			return ("");
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

void	tryAddContact(PhoneBook &book)
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
	bool		shouldReprompt;

	if (book.getNbContacts() == 0)
	{
		put_red_nl("No saved contacts");
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
		if (conv <= 0 || conv > book.getNbContacts())
			put_red_nl("Incorrect index");
		else
			book.getContactByIndex(conv - 1)->displayDetailed();
	}
}
