/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:00:43 by stopp             #+#    #+#             */
/*   Updated: 2025/01/23 12:39:07 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	try
	{
		getData();
	}
	catch (...)
	{
		std::cout << "caught" << std::endl;
	}
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
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Wrong Column Format!");

	std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
	while(std::getline(file,line))
	{
		std::string date, rate;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');

		if (!std::regex_match(date, dateRegex) || !isValidDate(date))
		{
			std::cout << date << std::endl;
			throw InvalidDateException();
		}
		double rateValue;

		std::istringstream rateStream(rate);
		if (!(rateStream >> rateValue))
			throw InvalidRateException();

		_rates[date] = rateValue;
	}
	file.close();
}
bool	BitcoinExchange::isValidDate(const std::string &date)
{
	std::istringstream ss(date);
	std::tm tm = {};
	ss >> std::get_time(&tm, "%Y-%m-%d"); // Parse date as YYYY-MM-DD
	// Check if parsing was successful and no leftover characters remain
	if (ss.fail() || !ss.eof())
		return false;
	if (tm.tm_mon > 11 || tm.tm_mday > 31)
		return false;
	if (tm.tm_mon == 1 && tm.tm_mday > 29)
		return false;
	if (((tm.tm_mon % 2 == 1 && tm.tm_mon < 7) || (tm.tm_mon % 2 != 1 && tm.tm_mon >= 7)) && tm.tm_mday > 30)
		return false;
	return true;
}

void	BitcoinExchange::multiplyPrint(const std::string date, double value)
{
	std::map<std::string, double>::iterator it = _rates.find(date);
	if (it != _rates.end())
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	else
	{
		it = _rates.lower_bound(date);
		if (it == _rates.begin())
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		else
		{
			it--;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
	}
}

double	BitcoinExchange::isValidPrice(const std::string priceStr)
{
	double priceRet;
	std::istringstream priceStream(priceStr);
	if (!(priceStream >> priceRet))
	{
		std::cout << "Error: bad value input => " << priceRet << std::endl;
		return (-1);
	}
	if (priceRet < 0)
	{
		std::cout << "Error: not a positive number. " << std::endl;
		return (-1);
	}
	if (priceRet > 1000)
	{
		std::cout << "Error: too large Number."<< std::endl;
		return (-1);
	}
	return (priceRet);
}

void	BitcoinExchange::exec(std::string filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		throw CantOpenFileException();

	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Wrong Column Format!");

	std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
	while(std::getline(file,line))
	{
		std::string date, price;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, price);
		if (!date.empty() && std::isspace(date.length() -2))
			date = date.erase(date.length() -1);
		if (!std::regex_match(date, dateRegex) || !isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		double priceValue = isValidPrice(price);
		if (priceValue != -1)
			multiplyPrint(date, priceValue);
	}
	file.close();
}
