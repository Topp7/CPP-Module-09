/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:58:20 by stopp             #+#    #+#             */
/*   Updated: 2025/01/23 12:33:44 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <map>
#include <regex>
#include <chrono>

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_rates;
		void							getData();

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		std::map<std::string, double>	&getRates() const;
		bool							isValidDate(const std::string &date);
		double							isValidPrice(const std::string priceStr);
		void							exec(std::string filename);
		void							multiplyPrint(const std::string date, double value);

		class CantOpenFileException : std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Can't open file");
				}
		};
		class InvalidDateException : std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid Date Format!");
				}
		};
		class InvalidRateException : std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid Rate!");
				}
		};
};
