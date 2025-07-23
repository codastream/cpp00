/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:02:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/23 12:35:02 by fpetit           ###   ########.fr       */
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
	return (!getFirstName().empty() \
		&& !getLastName().empty() \
		&& !getNickName().empty() \
		&& !getPhoneNumber().empty() \
		&& !getSecret().empty() \
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
		std::cout << std::setw(10) << field;
	else
		std::cout << field;
}

void	Contact::displayForBook(int index)
{
	std::cout << WHITE << "|";
	std::cout << "         " << index;
	std::cout << "|";
	putColumn(getFirstName());
	std::cout << "|";
	putColumn(getLastName());
	std::cout << "|";
	putColumn(getNickName());
	std::cout << "|" << NC << std::endl;
}

void	Contact::displayDetailed(void)
{
	put_blue("Name\t");
	putnl(getFirstName());
	put_blue("Last name");
	putnl(getLastName());
	put_blue("Nickname");
	putnl(getNickName());
	put_blue("Phone\t");
	putnl(getPhoneNumber());
	put_blue("Secret\t");
	putnl(getSecret());
}

std::string Contact::getSecret(void)
{
	return (_darkestSecret);
}

void		Contact::setSecret(std::string secret)
{
	_darkestSecret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (_firstName);
}

void		Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

std::string	Contact::getLastName(void)
{
	return (_lastName);

}

void		Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

std::string	Contact::getNickName(void)
{
	return (_nickName);
}

void		Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}

std::string	Contact::getPhoneNumber(void)
{
	return (_phoneNumber);
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}
