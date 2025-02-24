/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:05:40 by stopp             #+#    #+#             */
/*   Updated: 2025/02/24 15:35:25 by stopp            ###   ########.fr       */
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
};
