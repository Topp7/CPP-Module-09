/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:08:39 by stopp             #+#    #+#             */
/*   Updated: 2025/03/08 13:19:19 by stopp            ###   ########.fr       */
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
		this->_main = copy._main;
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
	// static int stat = 0;
	// std::cout << "Recursion lvl: " << stat++ << std::endl;
	for (std::vector<int>::iterator it = start; std::distance(it, end) >= elemSize; it += elemSize)
	{
		std::vector<int>::iterator first = it + (elemSize / 2) - 1;
		std::vector<int>::iterator second = it + elemSize - 1;
		this->sortElem(first, second, elemSize);
	}
	// std::cout << "Vector after recursion: ";
	// printInts(_dataVec);
	// std::cout << std::endl;
	this->mergeSort(elemSize * 2, this->_dataVec.begin(), this->_dataVec.end());
	if ((unsigned long)elemSize / 2 * 3 < _dataVec.size())
		insertion(elemSize);
	// std::cout << "rec lvl: " << stat-- << std::endl;
	// printInts(_dataVec);
	return;
}

std::vector<int>::iterator	PmergeVector::binary_search(int elemSize, std::vector<int>::iterator it_pend, std::vector<int>::iterator right)
{
	std::vector<int>::iterator	left = _main.begin() + elemSize - 1;
	std::vector<int>::iterator	mid;

	if(right > _main.end())
		right = _main.end() - 1;
	while (left < right - elemSize)
	{
		mid = (left + ((right - left) / 2) / elemSize * elemSize);
		if (*it_pend >= *mid)
			left = mid;
		else
			right = mid;
	}
	if (*it_pend >= *left && *it_pend < *right)
		return left + 1;
	else if(*it_pend >= *right)
		return right + 1;
	else
		return _main.begin();

}

void	PmergeVector::insertion(int elemSize)
{
	elemSize = elemSize / 2;
	int	i = 0;
	bool odd = false;
	while (_dataVec.size() >= (unsigned long)elemSize)
	{
		if (i == 0 || i % 2 == 1)
			std::copy(_dataVec.begin(), _dataVec.begin() + elemSize, std::back_inserter(_main));
		else
			std::copy(_dataVec.begin(), _dataVec.begin() + elemSize, std::back_inserter(_pend));
		_dataVec.erase(_dataVec.begin(), _dataVec.begin() + elemSize);
		i++;
	}
	if (i % 2 == 1)
	{
		odd = true;
		std::copy(_pend.end() - elemSize, _pend.end(), std::back_inserter(_odd));
		_pend.erase(_pend.end() - elemSize, _pend.end());
	}
	// std::cout << "elemsize: " << elemSize << std::endl;
	// std::cout << "main: "; printInts(_main); std::cout << std::endl;
	// std::cout << "pend: "; printInts(_pend); std::cout << std::endl;
	// std::cout << "odd: "; printInts(_odd); std::cout << std::endl;
	// std::cout << "dataVec: "; printInts(_dataVec); std::cout << std::endl;
	// std::cout << "amount of Ints: " << amount() << std::endl;
	if (elemSize > 0)
	{
		if (i > 6)
			binary_insert(elemSize, odd);
		else
			ordered_insert(elemSize, odd);
	}
}

void	PmergeVector::ordered_insert(int elemSize, bool odd)
{
	std::vector<int>::iterator it_pend;
	std::vector<int>::iterator it_main;
	while(_pend.size() > 0)
	{
		it_pend = _pend.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_pend, _main.end() - 1);
		_main.insert(it_main, it_pend  + 1 - elemSize, it_pend + 1);
		_pend.erase(_pend.begin(), it_pend + 1);
	}
	if (odd)
	{
		it_pend = _odd.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_pend, _main.end() - 1);
		_main.insert(it_main, it_pend  + 1 - elemSize, it_pend + 1);
		_odd.erase(_odd.begin(), it_pend + 1);
	}
	_dataVec.insert(_dataVec.begin(), _main.begin(), _main.end());
	_main.erase(_main.begin(), _main.end());
}

void	PmergeVector::binary_insert(int elemSize, bool odd)
{
	Jacobsthal Jac;
	int	inserted = 0;

	//order pend into main
	std::vector<int>::iterator it_pend;
	if ((elemSize * (Jac.get_curr() - Jac.get_prev()) - 1) > _pend.size())
		it_pend = _pend.end() - 1;
	else
		it_pend = _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev()) - 1);
	std::vector<int>::iterator it_main;
	while(_pend.size() > 0)
	{
		it_main = binary_search(elemSize, it_pend, _main.begin() + (elemSize * Jac.get_step()) - 1);
		_main.insert(it_main, it_pend + 1 - elemSize, it_pend + 1);
		inserted++;
		if (std::distance(_pend.begin(), it_pend) < elemSize)
		{
			if ((elemSize * (Jac.get_curr() - Jac.get_prev())) >= _pend.size())
			{
				_pend.erase(_pend.begin(), _pend.end());
				break;
			}
			else
				_pend.erase(_pend.begin(), _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev())));
			Jac.calc_next(inserted);
			if ((elemSize * (Jac.get_curr() - Jac.get_prev())) >= _pend.size())
				it_pend = _pend.end() - 1;
			else
				it_pend = _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev()) - 1);
		}
		else
			it_pend -= elemSize;
	}
	if (odd)
	{
		std::vector<int>::iterator	it_odd = _odd.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_odd, _main.end() - 1);
		_main.insert(it_main , it_odd - elemSize + 1, it_odd + 1);
		_odd.erase(_odd.begin(), _odd.end());
	}
	_dataVec.insert(_dataVec.begin(), _main.begin(), _main.end());
	_main.erase(_main.begin(), _main.end());
}

void	PmergeVector::FJA_vec()
{
	this->mergeSort(2, _dataVec.begin(), _dataVec.end());
	// printInts(_dataVec);
}

void	PmergeVector::getInts()
{
	for (int i = 0; (unsigned long)i < _dataVec.size(); i++)
		std::cout << _dataVec[i] << " ";
	std::cout << std::endl;
}

unsigned long	PmergeVector::amount()
{
	return _dataVec.size();
}
void	PmergeVector::check_order()
{
	bool ordered = true;
	bool doubleN = false;
	for (unsigned long i = 1; i < _dataVec.size(); i++)
	{
		if(*(_dataVec.begin() + i - 1) > *(_dataVec.begin() + i))
			ordered = false;
	}
	std::sort(_dataVec.begin(), _dataVec.end());
	for (unsigned long i = 1; i < _dataVec.size(); i++)
	{
		if(*(_dataVec.begin() + i - 1) == *(_dataVec.begin() + i))
			doubleN = true;
	}
	if (ordered == true)
		std::cout << "All sorted!" << std::endl;
	else
		std::cout << "Not sorted!" << std::endl;
	if (doubleN == true)
		std::cout << "Double Number!" << std::endl;
	else
		std::cout << "Not double!" << std::endl;
}




///deque
PmergeDeque::PmergeDeque()
{
}

PmergeDeque::PmergeDeque(const PmergeDeque &copy)
{
	*this = copy;
}

PmergeDeque &PmergeDeque::operator=(const PmergeDeque &copy)
{
	if (this != &copy)
	{
		this->_dataDeq = copy._dataDeq;
		this->_main = copy._main;
		this->_pend = copy._pend;
	}
	return (*this);
}

PmergeDeque::~PmergeDeque()
{
}

void	PmergeDeque::getInts(char **av)
{
	int	conv;
	for (int i = 1; av[i] != nullptr; i++)
	{
		try
		{
			conv = std::stoi(av[i]);
			this->_dataDeq.push_back(conv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return;
		}
	}
	this->_deqSize = _dataDeq.size();
}

void	PmergeDeque::sortElem(std::deque<int>::iterator first, std::deque<int>::iterator second, int elemSize)
{
	if (*first <= *second)
		return;
	std::deque<int>::iterator tempf = first;
	std::deque<int>::iterator temps = second;
	for (int i = 0; i < elemSize / 2; i++)
		std::iter_swap(tempf--, temps--);

}

void	PmergeDeque::mergeSort(int elemSize, std::deque<int>::iterator start, std::deque<int>::iterator end)
{
	if (_deqSize < elemSize)
		return ;
	// static int stat = 0;
	// std::cout << "Recursion lvl: " << stat++ << std::endl;
	for (std::deque<int>::iterator it = start; std::distance(it, end) >= elemSize; it += elemSize)
	{
		std::deque<int>::iterator first = it + (elemSize / 2) - 1;
		std::deque<int>::iterator second = it + elemSize - 1;
		this->sortElem(first, second, elemSize);
	}
	// std::cout << "Vector after recursion: ";
	// printInts(_dataDeq);
	// std::cout << std::endl;
	this->mergeSort(elemSize * 2, this->_dataDeq.begin(), this->_dataDeq.end());
	if ((unsigned long)elemSize / 2 * 3 < _dataDeq.size())
		insertion(elemSize);
	// std::cout << "rec lvl: " << stat-- << std::endl;
	// printInts(_dataDeq);
	return;
}

std::deque<int>::iterator	PmergeDeque::binary_search(int elemSize, std::deque<int>::iterator it_pend, std::deque<int>::iterator right)
{
	std::deque<int>::iterator	left = _main.begin() + elemSize - 1;
	std::deque<int>::iterator	mid;

	if(right > _main.end())
		right = _main.end() - 1;
	while (left < right - elemSize)
	{
		mid = (left + ((right - left) / 2) / elemSize * elemSize);
		if (*it_pend >= *mid)
			left = mid;
		else
			right = mid;
	}
	if (*it_pend >= *left && *it_pend < *right)
		return left + 1;
	else if(*it_pend >= *right)
		return right + 1;
	else
		return _main.begin();

}

void	PmergeDeque::insertion(int elemSize)
{
	elemSize = elemSize / 2;
	int	i = 0;
	bool odd = false;
	while (_dataDeq.size() >= (unsigned long)elemSize)
	{
		if (i == 0 || i % 2 == 1)
			std::copy(_dataDeq.begin(), _dataDeq.begin() + elemSize, std::back_inserter(_main));
		else
			std::copy(_dataDeq.begin(), _dataDeq.begin() + elemSize, std::back_inserter(_pend));
		_dataDeq.erase(_dataDeq.begin(), _dataDeq.begin() + elemSize);
		i++;
	}
	if (i % 2 == 1)
	{
		odd = true;
		std::copy(_pend.end() - elemSize, _pend.end(), std::back_inserter(_odd));
		_pend.erase(_pend.end() - elemSize, _pend.end());
	}
	// std::cout << "elemsize: " << elemSize << std::endl;
	// std::cout << "main: "; printInts(_main); std::cout << std::endl;
	// std::cout << "pend: "; printInts(_pend); std::cout << std::endl;
	// std::cout << "odd: "; printInts(_odd); std::cout << std::endl;
	// std::cout << "dataVec: "; printInts(_dataDeq); std::cout << std::endl;
	// std::cout << "amount of Ints: " << amount() << std::endl;
	if (elemSize > 0)
	{
		if (i > 6)
			binary_insert(elemSize, odd);
		else
			ordered_insert(elemSize, odd);
	}
}

void	PmergeDeque::ordered_insert(int elemSize, bool odd)
{
	std::deque<int>::iterator it_pend;
	std::deque<int>::iterator it_main;
	while(_pend.size() > 0)
	{
		it_pend = _pend.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_pend, _main.end() - 1);
		_main.insert(it_main, it_pend  + 1 - elemSize, it_pend + 1);
		_pend.erase(_pend.begin(), it_pend + 1);
	}
	if (odd)
	{
		it_pend = _odd.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_pend, _main.end() - 1);
		_main.insert(it_main, it_pend  + 1 - elemSize, it_pend + 1);
		_odd.erase(_odd.begin(), it_pend + 1);
	}
	_dataDeq.insert(_dataDeq.begin(), _main.begin(), _main.end());
	_main.erase(_main.begin(), _main.end());
}

void	PmergeDeque::binary_insert(int elemSize, bool odd)
{
	Jacobsthal Jac;
	int	inserted = 0;

	//order pend into main
	std::deque<int>::iterator it_pend;
	if ((elemSize * (Jac.get_curr() - Jac.get_prev()) - 1) > _pend.size())
		it_pend = _pend.end() - 1;
	else
		it_pend = _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev()) - 1);
	std::deque<int>::iterator it_main;
	while(_pend.size() > 0)
	{
		it_main = binary_search(elemSize, it_pend, _main.begin() + (elemSize * Jac.get_step()) - 1);
		_main.insert(it_main, it_pend + 1 - elemSize, it_pend + 1);
		inserted++;
		if (std::distance(_pend.begin(), it_pend) < elemSize)
		{
			if ((elemSize * (Jac.get_curr() - Jac.get_prev())) >= _pend.size())
			{
				_pend.erase(_pend.begin(), _pend.end());
				break;
			}
			else
				_pend.erase(_pend.begin(), _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev())));
			Jac.calc_next(inserted);
			if ((elemSize * (Jac.get_curr() - Jac.get_prev())) >= _pend.size())
				it_pend = _pend.end() - 1;
			else
				it_pend = _pend.begin() + (elemSize * (Jac.get_curr() - Jac.get_prev()) - 1);
		}
		else
			it_pend -= elemSize;
	}
	if (odd)
	{
		std::deque<int>::iterator	it_odd = _odd.begin() + elemSize - 1;
		it_main = binary_search(elemSize, it_odd, _main.end() - 1);
		_main.insert(it_main , it_odd - elemSize + 1, it_odd + 1);
		_odd.erase(_odd.begin(), _odd.end());
	}
	_dataDeq.insert(_dataDeq.begin(), _main.begin(), _main.end());
	_main.erase(_main.begin(), _main.end());
}

void	PmergeDeque::FJA_deq()
{
	this->mergeSort(2, _dataDeq.begin(), _dataDeq.end());
}

void	PmergeDeque::getInts()
{
	for (int i = 0; (unsigned long)i < _dataDeq.size(); i++)
		std::cout << _dataDeq[i] << " ";
	std::cout << std::endl;
}

unsigned long	PmergeDeque::amount()
{
	return _dataDeq.size();
}
void	PmergeDeque::check_order()
{
	bool ordered = true;
	bool doubleN = false;
	for (unsigned long i = 1; i < _dataDeq.size(); i++)
	{
		if(*(_dataDeq.begin() + i - 1) > *(_dataDeq.begin() + i))
			ordered = false;
	}
	std::sort(_dataDeq.begin(), _dataDeq.end());
	for (unsigned long i = 1; i < _dataDeq.size(); i++)
	{
		if(*(_dataDeq.begin() + i - 1) == *(_dataDeq.begin() + i))
			doubleN = true;
	}
	if (ordered == true)
		std::cout << "All sorted!" << std::endl;
	else
		std::cout << "Not sorted!" << std::endl;
	if (doubleN == true)
		std::cout << "Double Number!" << std::endl;
	else
		std::cout << "Not double!" << std::endl;
}
