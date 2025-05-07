/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:03:44 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 19:33:01 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define MAX_CONTACTS 8

# include <iostream>
class Contact
{
	private:
	std::string _darkestSecret;
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;

	public:
	Contact(void);
	~Contact(void);
	std::string getSecret(void);
	void		setSecret(std::string secret);
	std::string	getFirstName(void);
	void		setFirstName(std::string firstName);
	std::string	getLastName(void);
	void		setLastName(std::string lastName);
	std::string	getNickName(void);
	void		setNickName(std::string nickName);
	std::string	getPhoneNumber(void);
	void		setPhoneNumber(std::string phoneNumber);
	bool		isFilledUp(void);
	void		displayForBook(int index);
	void		displayDetailed(void);

};

#endif
