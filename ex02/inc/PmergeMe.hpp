/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:07:22 by soren             #+#    #+#             */
/*   Updated: 2025/02/06 14:26:03 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <ctime>
#include <exception>

class FJA_I
{
	public:
		virtual ~FJA_I() {};

		virtual void	getInts(char **av) = 0;
		virtual void	mergeSort(int elemSize, std::vector<int>::iterator start, std::vector<int>::iterator end) = 0;
		virtual void	sortElem(std::vector<int>::iterator first, std::vector<int>::iterator second, int elemSize) = 0;
		// virtual void	sortPairs() = 0;
		// virtual void	merge() = 0;

};


class PmergeVector : public FJA_I
{
	private:
		std::vector<int>	_dataVec;
		std::vector<int>	_mainChain;
		std::vector<int>	_pend;
		int					_vecSize;

	public:
		PmergeVector();
		PmergeVector(const PmergeVector &copy);
		PmergeVector &operator=(const PmergeVector &copy);
		~PmergeVector();

		void	getInts(char **av) override;
		void	printInts();
		void	mergeSort(int elemSize, std::vector<int>::iterator start, std::vector<int>::iterator end) override;
		void	sortElem(std::vector<int>::iterator first, std::vector<int>::iterator second, int elemSize) override;
		void	FJA_vec();
};
