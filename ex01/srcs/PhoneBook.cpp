/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:21 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/18 21:32:08 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	swapContacts(Contact *p1, Contact *p2)
{
	Contact	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	PhoneBook::addContact(Contact& contact)
{
	unsigned int	addIndex;

	if (this->getNbContacts() == MAX_CONTACTS)
	{
		addIndex = 0;
	}
	else
	{
		this->_incrementNbContacts();
		addIndex = this->getNbContacts() - 1;
	}
	_setContactByIndex(contact, addIndex);
}

void	PhoneBook::displayPhonebook(void)
{
	std::cout << std::endl << BWHITE << "|" << std::setw(11)  << "index|" << "first name|" << " last name|" \
		<< "  nickname|" << NC << std::endl;
	for (int i = 0; i < this->getNbContacts(); i++)
	{
		this->getContacts()[i].displayForBook(i + 1);
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
		this->_contacts[index] = contact;
	}
}

void	PhoneBook::_incrementNbContacts(void)
{
	this->_nbContacts++;
}
