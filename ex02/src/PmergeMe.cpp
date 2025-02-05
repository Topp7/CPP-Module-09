/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:08:39 by stopp             #+#    #+#             */
/*   Updated: 2025/02/05 17:57:16 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeVector::PmergeVector()
{
}

PmergeVector::PmergeVector(const PmergeVector &copy)
{
	*this = copy;
}

PmergeVector &PmergeVector::operator=(const PmergeVector &copy)
{
	if (this != &copy)
	{
		this->dataVec = copy.dataVec;
		this->mainChain = copy.mainChain;
		this->pend = copy.pend;
	}
	return (*this);
}

PmergeVector::~PmergeVector()
{
}

void	PmergeVector::getInts(char **av)
{
	int	conv;
	for (int i = 1; av[i]; i++)
	{
		try
		{
			conv = std::stoi(av[i]);
			this->dataVec.push_back(conv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	PmergeVector::printInts()
{
	for (int i = 0; dataVec[i]; i++)
		std::cout << dataVec[i] << std::endl;
}
