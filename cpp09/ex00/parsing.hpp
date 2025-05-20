/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:05 by pscala            #+#    #+#             */
/*   Updated: 2025/05/20 20:00:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

bool isGoodExensionFile(std::string file, std::string extension);
bool parseLine(std::istringstream &ss, std::string &date, std::string &btcValue, char separator, int flag);
void trim(std::string &str);
bool isValidDate(const std::string &date);
bool isValidValue(const std::string &value, int flag);
bool isStrDigits(const std::string &str);
bool isValidYear(const std::string &year, const std::string &month, const std::string &date);
