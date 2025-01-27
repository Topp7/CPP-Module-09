/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:10:45 by stopp             #+#    #+#             */
/*   Updated: 2025/01/27 14:56:15 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN	&RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

RPN::~RPN()
{
}

RPN::RPN(const std::string &input)
{
	std::stringstream ss(input);
	std::string	tok;
	int	n;

	while(std::getline(ss, tok, ' '))
	{
		if ((tok.length() == 1 && isdigit(tok[0])) || (tok.length() == 2 && tok[0] == '-' && isdigit(tok[1])))
		{
			std::stringstream(tok) >> n;
			_stack.push(n);
		}
		else if (tok == "+")
			_exec(&RPN::_plus);
		else if (tok == "-")
			_exec(&RPN::_minus);
		else if (tok == "*")
			_exec(&RPN::_multiply);
		else if (tok == "/")
			_exec(&RPN::_divide);
		else
			throw std::runtime_error("Invalid argument: " + tok);
	}
}

void	RPN::_exec(double (RPN::*f)(double, double))
{
	double a;
	double b;

	if (_stack.size() < 2)
		throw	std::runtime_error("Empty Stack");
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push((this->*f)(a, b));
}
double	RPN::result() const
{
	if (_stack.empty())
		throw	std::runtime_error("Empty Stack");
	else if (_stack.size() > 1)
		throw	std::runtime_error("Invalid Argument");
	return (_stack.top());
}

double RPN::_plus(double a, double b)
{
	return (a + b);
}
double RPN::_minus(double a, double b)
{
	return (b - a);
}
double RPN::_multiply(double a, double b)
{
	return (b * a);
}
double RPN::_divide(double a, double b)
{
	if (a == 0)
		throw std::runtime_error("divided by zero");
	return (b / a);
}
