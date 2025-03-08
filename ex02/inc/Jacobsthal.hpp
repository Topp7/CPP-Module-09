/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:40 by stopp             #+#    #+#             */
/*   Updated: 2025/03/04 13:38:28 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

class Jacobsthal
{
	private:
		size_t _a;
		size_t _b;
		size_t _step;

	public:
		Jacobsthal();
		Jacobsthal(const Jacobsthal &copy);
		Jacobsthal &operator=(const Jacobsthal &copy);
		~Jacobsthal();

		void	calc_next(int inserted);
		size_t	get_curr();
		size_t	get_prev();
		size_t	get_step();
};
