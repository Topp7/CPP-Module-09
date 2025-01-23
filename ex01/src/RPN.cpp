/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:45 by stopp             #+#    #+#             */
/*   Updated: 2025/01/23 13:14:42 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RNP.hpp"

RPN::RPN()
{
}
RPN::PRN(const RPN &copy)
{
	*this = copy;
}

RPN	&RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

RPN::
