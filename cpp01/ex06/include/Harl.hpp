/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:44:47 by pscala            #+#    #+#             */
/*   Updated: 2025/01/27 11:07:35 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		int complain(std::string level);
};
