/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:13:22 by pscala            #+#    #+#             */
/*   Updated: 2025/05/23 01:06:16 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class RPN
{
	private:
		std::stack<int> _stack;
		RPN();

		void execOperation(const std::string &operation);
		void calculate(const char &operand);

	public:
		RPN(const std::string &operation);
		RPN(const RPN &cpy);
		~RPN();
		RPN &operator=(const RPN &src);
};

void parseOperation(const std::string &operation);
bool isOperand(const char c);
