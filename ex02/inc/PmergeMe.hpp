/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:07:22 by soren             #+#    #+#             */
/*   Updated: 2025/03/07 17:00:24 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <ctime>
#include <iterator>
#include <exception>
#include "Jacobsthal.hpp"

class PmergeVector
{
	private:
		std::vector<int>	_dataVec;
		std::vector<int>	_main;
		std::vector<int>	_pend;
		std::vector<int>	_odd;
		int					_vecSize;

	public:
		PmergeVector();
		PmergeVector(const PmergeVector &copy);
		PmergeVector &operator=(const PmergeVector &copy);
		~PmergeVector();

		void	getInts(char **av);
		void	getInts();
		void	mergeSort(int elemSize, std::vector<int>::iterator start, std::vector<int>::iterator end);
		void	sortElem(std::vector<int>::iterator first, std::vector<int>::iterator second, int elemSize);
		void	FJA_vec();
		void	insertion(int elemSize);
		void	binary_insert(int elemSize, bool odd);
		void	ordered_insert(int elemSize, bool odd);
		void	check_order();
		unsigned long	amount();
		std::vector<int>::iterator	binary_search(int elemSize, std::vector<int>::iterator it_pend, std::vector<int>::iterator right);
};

class PmergeDeque
{
	private:
		std::deque<int>	_dataDeq;
		std::deque<int>	_main;
		std::deque<int>	_pend;
		std::deque<int>	_odd;
		int				_deqSize;

	public:
		PmergeDeque();
		PmergeDeque(const PmergeDeque &copy);
		PmergeDeque &operator=(const PmergeDeque &copy);
		~PmergeDeque();

		void	getInts(char **av);
		void	getInts();
		void	mergeSort(int elemSize, std::deque<int>::iterator start, std::deque<int>::iterator end);
		void	sortElem(std::deque<int>::iterator first, std::deque<int>::iterator second, int elemSize);
		void	FJA_deq();
		void	insertion(int elemSize);
		void	binary_insert(int elemSize, bool odd);
		void	ordered_insert(int elemSize, bool odd);
		void	check_order();
		unsigned long	amount();
		std::deque<int>::iterator	binary_search(int elemSize, std::deque<int>::iterator it_pend, std::deque<int>::iterator right);
};
