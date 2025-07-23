/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:03:44 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/23 13:22:41 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define MAX_CONTACTS 8

# include <iostream>
class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		setSecret(std::string secret);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setPhoneNumber(std::string phoneNumber);
		bool		isFilledUp(void);
		void		displayForBook(int index);
		void		displayDetailed(void);
		
	private:
		std::string	getFirstName(void);
		std::string getSecret(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string _darkestSecret;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;

};

#endif
