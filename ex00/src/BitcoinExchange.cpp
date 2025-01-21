/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:00:43 by stopp             #+#    #+#             */
/*   Updated: 2025/01/21 12:42:27 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	getData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_rates = copy._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::getData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw CantOpenFileException();

	std::string line;
	while(std::getline(file, line))
	{
		std::istringstream	stream(line);
		std::string			date();
		std::string			valueStr();
	}
}
