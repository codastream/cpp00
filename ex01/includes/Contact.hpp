/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:03:44 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 16:02:36 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define MAX_CONTACTS 8

# include <iostream>
class Contact
{
private:
	std::string darkest_secret;

	public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;

	Contact(void);
	~Contact(void);
	std::string getSecret(void);
	void		setSecret(std::string secret);
	bool		isFilledUp(void);
	void		displayForBook(int index);
	void		displayDetailed(void);

};

#endif
