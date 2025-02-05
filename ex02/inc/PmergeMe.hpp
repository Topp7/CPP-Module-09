/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:07:22 by soren             #+#    #+#             */
/*   Updated: 2025/02/05 17:55:56 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <ctime>
#include <exception>

class FJA
{
	public:
		virtual ~FJA() {};

		virtual void	getInts(char **av) = 0;
		// virtual void	createPairs() = 0;
		// virtual void	sortPairs() = 0;
		// virtual void	merge() = 0;

};


class PmergeVector : public FJA
{
	private:
		std::vector<int> dataVec;
		std::vector<int> mainChain;
		std::vector<int> pend;

	public:
		PmergeVector();
		PmergeVector(const PmergeVector &copy);
		PmergeVector &operator=(const PmergeVector &copy);
		~PmergeVector();

		void	getInts(char **av) override;
		void	printInts();
};
