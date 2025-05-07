/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:27 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 20:38:44 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
	void	_reorderByAgeDesc(void);
	Contact _contacts[8];
	int		_nbContacts;
	void	_incrementNbContacts( void );
	void	_setContactByIndex( Contact& contact, int index );

	public:
	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(Contact& contact);
	void	displayPhonebook(void);

	Contact*		getContacts( void );
	int 			getNbContacts( void );
	Contact*		getContactByIndex( int index );

};

#endif
