/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:21 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 20:51:40 by fpetit           ###   ########.fr       */
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

/*
Brings the oldest contact to last index so that it can be replaced by next addition
*/
void	PhoneBook::_reorderByAgeDesc(void)
{
	for (int i = 0; i < this->getNbContacts() - 1; i++)
	{
		swapContacts(&this->_contacts[i], &this->_contacts[i + 1]);
	}
}

void	PhoneBook::addContact(Contact& contact)
{
	if (this->getNbContacts() == MAX_CONTACTS)
		_reorderByAgeDesc();
	else
		this->_incrementNbContacts();
	_setContactByIndex(contact, this->getNbContacts() - 1);
}

void	PhoneBook::displayPhonebook(void)
{
	for (int i = 0; i < this->getNbContacts(); i++)
	{
		this->getContacts()[i].displayForBook(i + 1);
	}
}

Contact*	PhoneBook::getContacts( void )
{
	return (_contacts);
}

Contact*	PhoneBook::getContactByIndex( int index )
{
	if (index >= 0 && index <= MAX_CONTACTS - 1)
	{
		return (&_contacts[index]);
	}
	else
		return (0);
}

int 		PhoneBook::getNbContacts( void )
{
	return (_nbContacts);
}

void	PhoneBook::_setContactByIndex( Contact& contact, int index )
{
	if (index >= 0 && index <= MAX_CONTACTS - 1)
	{
		this->_contacts[index] = contact;
	}
}

void	PhoneBook::_incrementNbContacts( void )
{
	this->_nbContacts++;
}
