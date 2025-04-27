/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:21 by fpetit            #+#    #+#             */
/*   Updated: 2025/04/27 21:14:23 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"

PhoneBook::PhoneBook(void)
{
	this->nb_contacts = 0;
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
void	PhoneBook::reorderByAgeDesc(void)
{
	for (int i = 0; i < this->nb_contacts - 1; i++)
	{
		swapContacts(&this->contacts[i], &this->contacts[i + 1]);
	}
}

void	PhoneBook::addContact(Contact contact)
{
	if (this->nb_contacts == MAX_CONTACTS)
		reorderByAgeDesc();
	else
		this->nb_contacts++;
	contacts[nb_contacts - 1] = contact;
}

void	PhoneBook::displayPhonebook(void)
{
	for (int i = 0; i <= this->nb_contacts; i++)
	{
		this->contacts[i].displayForBook(i + 1);
	}
}
