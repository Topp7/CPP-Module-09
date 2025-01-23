/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:55:52 by stopp             #+#    #+#             */
/*   Updated: 2025/01/23 13:12:56 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <exception>

class RPN
{
	private:
		std::stack<double>	_stack;
		void				_exec(double (RPN::*f)(double, double));
		double				_plus(double a, double b);
		double				_minus(double a, double b);
		double				_multiply(double a, double b);
		double				_divide(double a, double b);

	public:
		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &copy);
		~RPN();
		RPN(const std::string &input);

		double	result() const;
};
