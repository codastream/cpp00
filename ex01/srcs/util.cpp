/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:53:10 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 20:45:09 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.hpp"

void	putnl(std::string msg)
{
	std::cout << msg << std::endl;
}

void	put_red_nl(std::string msg)
{
	std::cout << RED << msg << NC << std::endl;
}

void	put_green_nl(std::string msg)
{
	std::cout << GREEN << msg << NC << std::endl;
}

void	put_blue(std::string msg)
{
	std::cout << BLUE << msg << NC << "\t";
}
