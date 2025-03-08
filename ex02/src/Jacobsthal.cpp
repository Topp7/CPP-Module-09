/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:40 by stopp             #+#    #+#             */
/*   Updated: 2025/03/04 13:39:01 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Jacobsthal.hpp"

Jacobsthal::Jacobsthal() : _a(1), _b(3), _step(3)
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

void	Jacobsthal::calc_next(int inserted)
{
	size_t tmp = (2 * _a) + _b;
	_a = _b;
	_b = tmp;
	_step = inserted + _b;
}
size_t	Jacobsthal::get_curr()
{
	return _b;
}

size_t	Jacobsthal::get_prev()
{
	return _a;
}
size_t Jacobsthal::get_step()
{
	return _step;
}
