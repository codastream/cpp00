/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:21 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/23 13:27:28 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

PhoneBook::PhoneBook(void)
{
	_nbContacts = 0;
	_insertCount = -1;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::addContact(Contact& contact)
{
	int	insertIndex;

	if (getNbContacts() == MAX_CONTACTS)
	{
		_insertCount++;
		insertIndex = _insertCount % 8;
	}
	else
	{
		_incrementNbContacts();
		insertIndex = getNbContacts() - 1;
	}
	_setContactByIndex(contact, insertIndex);
}

void	PhoneBook::displayPhonebook(void)
{
	std::cout << std::endl << BWHITE << "|" << std::setw(11)  << "index|" << "first name|" << " last name|" \
		<< "  nickname|" << NC << std::endl;
	for (int i = 0; i < getNbContacts(); i++)
	{
		getContacts()[i].displayForBook(i + 1);
	}
	std::cout << std::endl;
}

Contact*	PhoneBook::getContacts(void)
{
	return (_contacts);
}

Contact*	PhoneBook::getContactByIndex(int index)
{
	if (index >= 0 && index <= MAX_CONTACTS - 1)
	{
		return (&_contacts[index]);
	}
	else
		return (0);
}

int 		PhoneBook::getNbContacts(void)
{
	return (_nbContacts);
}

void	PhoneBook::_setContactByIndex(Contact& contact, int index)
{
	if (index >= 0 && index <= MAX_CONTACTS - 1)
	{
		_contacts[index] = contact;
	}
}

void	PhoneBook::_incrementNbContacts(void)
{
	_nbContacts++;
}
