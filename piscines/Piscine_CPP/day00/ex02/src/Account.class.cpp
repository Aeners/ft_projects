/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaudsmac <arnaudsmac@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:21:21 by arlecomt          #+#    #+#             */
/*   Updated: 2019/03/04 19:42:32 by arnaudsmac       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "../Account.class.hpp"

Account::Account(int initial_deposit) : _accountIndex(getNbAccounts()),
																				_amount(initial_deposit),
																				_nbDeposits(0),
																				_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
						<< ";amount:" << this->_amount
						<< ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
						<< ";amount:" << this->_amount
						<< ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
						<< ";total:" << Account::_totalAmount
						<< ";deposits:" << Account::_totalNbDeposits
						<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
						<< ";p_amount:" << this->_amount - deposit
						<< ";deposit:" << deposit
						<< ";amount:" << this->_amount
						<< ";nb_deposits:" << this->_nbDeposits
						<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
						<< ";p_amount:" << this->_amount
						<< ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal
						<< ";amount:" << this->_amount
						<< ";nb_withdrawals:" << this->_nbWithdrawals
						<< std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	this->_checkAmountCalled++;
	std::cout << "checkAmount method called " << this->_checkAmountCalled << " times" << std::endl;
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
						<< ";amount:" << this->_amount
						<< ";deposits:" << this->_nbDeposits
						<< ";withdrawals:" << this->_nbWithdrawals
						<< std::endl;
}

void Account::_displayTimestamp(void)
{
	char str[100];
	std::time_t t = std::time(nullptr);

	if (std::strftime(str, sizeof(str), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
	{
		std::cout << str;
	}
}

Account::Account(void) {}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;