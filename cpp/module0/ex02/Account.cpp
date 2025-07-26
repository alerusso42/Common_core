/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 07:09:52 by codespace         #+#    #+#             */
/*   Updated: 2025/07/26 12:43:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "general.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::checkAmount(void) const
{
	return (_amount);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	//accounts:8;total:20049;deposits:0;withdrawals:0
	std::cout << TIMESTAMP;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
	std::cout << TIMESTAMP;
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
	std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
}

Account::Account(void)
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
}

Account::~Account(void)
{
	std::cout << TIMESTAMP;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	std::cout << TIMESTAMP;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbDeposits << ";";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	std::cout << TIMESTAMP;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << ":refused" << std::endl;
		return (1);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
	return (0);
}
