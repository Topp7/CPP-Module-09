/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:59:56 by soren             #+#    #+#             */
/*   Updated: 2025/03/07 17:12:21 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	clock_t	timeVec;
	clock_t	timeDeq;
	if (argc < 2)
	{
		std::cerr << "Invalid amount of Arguments!" << std::endl;
		return (1);
	}
	PmergeVector vec;
	PmergeDeque	 deq;
	vec.getInts(argv);
	deq.getInts(argv);
	std::cout << "Before: "; vec.getInts(); std::cout << std::endl;
	// std::cout << "Before: "; deq.getInts(); std::cout << std::endl;
	timeVec = clock();
	vec.FJA_vec();
	timeVec = clock() - timeVec;
	timeDeq = clock();
	deq.FJA_deq();
	timeDeq = clock() - timeDeq;
	// vec.check_order();
	// deq.check_order();
	std::cout << "After: "; vec.getInts(); std::cout << std::endl;
	// std::cout << "After: "; deq.getInts(); std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.amount() << " elements with std::vector: " << (float)timeVec * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << "Time to process a range of " << vec.amount() << " elements with std::deque: " << (float)timeDeq * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;
}
