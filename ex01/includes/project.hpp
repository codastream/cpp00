/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:15:19 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/17 18:38:36 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <cctype>
# include "Contact.hpp"
# include "PhoneBook.hpp"

# define NC      "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

# define MSG_COMMAND "Please enter any of following : ADD, SEARCH, EXIT"
# define MSG_ERRARG "Usage : ./phonebook (No argument required)"

void	searchContact(PhoneBook& book);
void	refill8Contacts(PhoneBook& book);
void	tryAddContact(PhoneBook& book);
void	putnl(std::string msg);
void	put_blue(std::string msg);
void	put_green_nl(std::string msg);
void	put_red_nl(std::string msg);

#endif
