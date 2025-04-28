/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Project.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:15:19 by fpetit            #+#    #+#             */
/*   Updated: 2025/04/28 18:59:13 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <cstdlib>
# include "Contact.hpp"
# include "PhoneBook.hpp"

# define MSG_COMMAND "Please enter any of following : ADD, SEARCH, EXIT"
# define MSG_ERRARG "Usage : ./phonebook (No argument required)"

void	searchContact(PhoneBook &book);
void	tryAddContact(PhoneBook &book);
void	putnl(std::string msg);

#endif
