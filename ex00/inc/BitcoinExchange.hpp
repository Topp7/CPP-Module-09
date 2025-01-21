/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:58:20 by stopp             #+#    #+#             */
/*   Updated: 2025/01/20 18:27:02 by stopp            ###   ########.fr       */
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
		void							exec(std::string filename);

		class CantOpenFileException : std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Can't open file");
				}
		}
};
