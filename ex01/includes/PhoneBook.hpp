/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:00:27 by fpetit            #+#    #+#             */
/*   Updated: 2025/04/27 21:43:16 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
	void	reorderByAgeDesc(void);

	public:

	Contact contacts[8];
	int		nb_contacts;

	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(Contact &contact);
	void	displayPhonebook(void);
};

#endif
