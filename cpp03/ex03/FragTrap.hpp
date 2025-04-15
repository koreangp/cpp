/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:26:30 by pscala            #+#    #+#             */
/*   Updated: 2025/02/10 16:33:46 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap &copy);
    ~FragTrap();

    FragTrap &operator=(FragTrap &src);

    void highFivesGuys();
};
