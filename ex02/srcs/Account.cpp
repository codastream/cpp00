/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:00:01 by fpetit            #+#    #+#             */
/*   Updated: 2025/05/07 16:15:22 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"\
		<< "total:" << _totalAmount << ";"\
		<< "deposits:" << _totalNbDeposits << ";"\
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"\
		<< "amount:" << _amount << ";"\
		<< "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"\
		<< "amount:" << _amount << ";"\
		<< "closed" << std::endl;
	Account::_nbAccounts--;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit >= 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"\
			<< "p_amount:" << checkAmount() << ";"\
			<< "deposit:" << deposit << ";";
		_amount += deposit;
		_totalAmount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
		std::cout << "amount:" << checkAmount() << ";"\
			<< "nb_deposits:" << _nbDeposits << std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"\
		<< "p_amount:" << checkAmount() << ";"\
		<< "withdrawal:";
	if (withdrawal >= 0)
	{
		if (_amount - withdrawal < 0)
		{
			std::cout << "refused" << std::endl;
			return (false);
		}
		else
		{
			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			_nbWithdrawals++;
			_totalNbWithdrawals++;
			std::cout << withdrawal << ";"\
			<< "amount:" << checkAmount() << ";"\
			<< "nb_withdrawals:" << _nbWithdrawals\
			<< std::endl;
			return (true);
		}
	}
	else
		return (false);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"\
		<< "amount:" << _amount << ";"\
		<< "deposits:" << _nbDeposits << ";"\
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::_displayTimestamp( void )
{
	time_t	now;
	std::tm	*now_local;
	char	buffer[20];

	now = time(NULL);
	now_local = localtime(&now);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now_local);
	std::cout << buffer;
}
