/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soren <soren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:40 by stopp             #+#    #+#             */
/*   Updated: 2025/02/26 13:59:51 by soren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Jacobsthal.hpp"

Jacobsthal::Jacobsthal() : _a(1), _b(3)
{
}
Jacobsthal::Jacobsthal(const Jacobsthal &copy)
{
	*this = copy;
}

Jacobsthal &Jacobsthal::operator=(const Jacobsthal &copy)
{
	if (this != &copy)
	{
		_a = copy._a;
		_b = copy._b;
	}
	return *this;
}

Jacobsthal::~Jacobsthal()
{
}

void	Jacobsthal::calc_next(void)
{
	size_t tmp = (2 * _a) + _b;
	_a = _b;
	_b = tmp;
}
size_t	Jacobsthal::get_curr()
{
	return _b;
}

size_t	Jacobsthal::get_prev()
{
	return _a;
}
