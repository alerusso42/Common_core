/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 07:09:52 by codespace         #+#    #+#             */
/*   Updated: 2025/07/12 08:37:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


	static int	getNbAccounts(void)
	{
		int			nb;
		accounts_t	start;
		accounts_t	end;
	
		start = _account;
	}
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
	static void	_displayTimestamp( void );