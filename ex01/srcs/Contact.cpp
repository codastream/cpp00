/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:02:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 20:45:27 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void) {
	return;
}

bool	Contact::isFilledUp()
{
	return (!this->getFirstName().empty() \
		&& !this->getLastName().empty() \
		&& !this->getNickName().empty() \
		&& !this->getPhoneNumber().empty() \
		&& !this->getSecret().empty() \
	);
}

void	putColumn(std::string field)
{
	int	len;

	len = field.length();
	if (len > 10)
	{
		std::cout << field.substr(0, 9);
		std::cout << ".";
	}
	else if (len < 10)
	{
		for (int i = len; i < 10; i++)
			std::cout << " ";
		std::cout << field;
	}
	else
		std::cout << field;
}

void	Contact::displayForBook(int index)
{
	std::cout << "|";
	std::cout << "         " << index;
	std::cout << "|";
	putColumn(this->getFirstName());
	std::cout << "|";
	putColumn(this->getLastName());
	std::cout << "|";
	putColumn(this->getNickName());
	std::cout << "|" << std::endl;
}

void	Contact::displayDetailed(void)
{
	put_blue("Name\t");
	putnl(this->getFirstName());
	put_blue("Last name");
	putnl(this->getLastName());
	put_blue("Nickname");
	putnl(this->getNickName());
	put_blue("Phone\t");
	putnl(this->getPhoneNumber());
	put_blue("Secret\t");
	putnl(this->getSecret());
}

std::string Contact::getSecret(void)
{
	return (this->_darkestSecret);
}

void		Contact::setSecret(std::string secret)
{
	this->_darkestSecret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

void		Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);

}

void		Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getNickName(void)
{
	return (this->_nickName);
}

void		Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
