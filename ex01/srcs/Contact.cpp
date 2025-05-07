/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:02:06 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 16:37:18 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void) {
	return;
}

std::string	Contact::getSecret(void)
{
	return (darkest_secret);
}

void	Contact::setSecret(std::string secret)
{
	darkest_secret = secret;
}

bool	Contact::isFilledUp()
{
	return (!this->first_name.empty() \
		&& !this->last_name.empty() \
		&& !this->nickname.empty() \
		&& !this->phone_number.empty() \
		&& !this->darkest_secret.empty() \
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
	putColumn(this->first_name);
	std::cout << "|";
	putColumn(this->last_name);
	std::cout << "|";
	putColumn(this->nickname);
	std::cout << "|" << std::endl;
}

void	Contact::displayDetailed(void)
{
	put_blue("Name\t");
	putnl(this->first_name);
	put_blue("Last name");
	putnl(this->last_name);
	put_blue("Nickname");
	putnl(this->nickname);
	put_blue("Phone\t");
	putnl(this->phone_number);
	put_blue("Secret\t");
	putnl(this->darkest_secret);
}
