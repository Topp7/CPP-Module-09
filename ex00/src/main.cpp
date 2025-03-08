/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:40:25 by stopp             #+#    #+#             */
/*   Updated: 2025/03/08 12:22:16 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Invalid amount of Arguments" << std::endl;

	BitcoinExchange	btcExchange;
	// if (btcExchange.isValidDate("2020-02-29"))
	// 	std::cout << "valid Date" << std::endl;
	// else
	// 	std::cout << "Invalid Date" << std::endl;
	try
	{
		btcExchange.exec(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
