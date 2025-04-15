/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:30 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 16:33:50 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &copy);
    ~ScavTrap();

    ScavTrap &operator=(ScavTrap &src);

    void guardGate();
};
