/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:52:06 by pscala            #+#    #+#             */
/*   Updated: 2025/04/17 13:21:44 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "color.hpp"

class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();

  public:
	static void convert(const std::string &str);
};
