/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:52:12 by pscala            #+#    #+#             */
/*   Updated: 2025/01/26 15:54:25 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"

class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		const std::string& getType() const;
		void	setType(const std::string& newType);
};
