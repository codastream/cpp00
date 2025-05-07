/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:53:10 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 16:02:46 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"

void	putnl(std::string msg)
{
	std::cout << msg << std::endl;
}

void	putnlblue(std::string msg)
{
	std::cout << BLUE << msg << NC << std::endl;
}
