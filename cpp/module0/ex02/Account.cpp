/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 07:09:52 by codespace         #+#    #+#             */
/*   Updated: 2025/07/26 11:20:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "general.hpp"

/*
	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;
	*/

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

void	Account::displayAccountsInfos(void)
{
	//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
	std::cout << TIMESTAMP;
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalAmount << ";";
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
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
}