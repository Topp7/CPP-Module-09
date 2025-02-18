/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:08:39 by stopp             #+#    #+#             */
/*   Updated: 2025/02/18 16:27:06 by stopp            ###   ########.fr       */
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
		this->_dataVec = copy._dataVec;
		this->_mainChain = copy._mainChain;
		this->_pend = copy._pend;
	}
	return (*this);
}

PmergeVector::~PmergeVector()
{
}

void	PmergeVector::getInts(char **av)
{
	int	conv;
	for (int i = 1; av[i] != nullptr; i++)
	{
		try
		{
			conv = std::stoi(av[i]);
			this->_dataVec.push_back(conv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return;
		}
	}
	this->_vecSize = _dataVec.size();
}

void	PmergeVector::sortElem(std::vector<int>::iterator first, std::vector<int>::iterator second, int elemSize)
{
	if (*first <= *second)
		return;
	std::vector<int>::iterator tempf = first;
	std::vector<int>::iterator temps = second;
	for (int i = 0; i < elemSize / 2; i++)
		std::iter_swap(tempf--, temps--);

}

void	PmergeVector::mergeSort(int elemSize, std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (_vecSize < elemSize)
		return ;
	static int stat = 0;
	std::cout << "Recursion lvl: " << stat++ << std::endl;
	for (std::vector<int>::iterator it = start; it + elemSize <= end; it += elemSize)
	{
		std::vector<int>::iterator first = it + (elemSize / 2) - 1;
		std::vector<int>::iterator second = it + elemSize - 1;
		this->sortElem(first, second, elemSize);
	}
	std::cout << "Vector after recursion lvl: ";
	printInts();
	std::cout << std::endl;
	this->mergeSort(elemSize * 2, this->_dataVec.begin(), this->_dataVec.end());
	if (elemSize * 3 < _dataVec.size())
	{
		insertion(elemSize);
		container_cleanup();
	}
	return;
}

void	PmergeVector::insertion(int elemSize)
{
	elemSize = elemSize / 2;
	for (int i = 0; (i * elemSize) + elemSize < _dataVec.size(); i++)
	{
		if (i == 0 || i % 2 == 1)
			std::copy(_dataVec.begin() + (i * elemSize), _dataVec.begin() + (i * elemSize) + elemSize, std::back_inserter(_main));
		else
			std::copy(_dataVec.begin() + (i * elemSize), _dataVec.begin() + (i * elemSize) + elemSize, std::back_inserter(_pend));
	}
}

void	PmergeVector::FJA_vec()
{
	this->mergeSort(2, _dataVec.begin(), _dataVec.end());
}

void	PmergeVector::printInts()
{
	for (int i = 0; i < _vecSize; i++)
		std::cout << _dataVec[i] << " ";
	std::cout << std::endl;
}
