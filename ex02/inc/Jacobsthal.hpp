/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soren <soren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:40 by stopp             #+#    #+#             */
/*   Updated: 2025/02/26 13:59:38 by soren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

class Jacobsthal
{
	private:
		size_t _a;
		size_t _b;

	public:
		Jacobsthal();
		Jacobsthal(const Jacobsthal &copy);
		Jacobsthal &operator=(const Jacobsthal &copy);
		~Jacobsthal();

		void	calc_next(void);
		size_t	get_curr();
		size_t	get_prev();
};
