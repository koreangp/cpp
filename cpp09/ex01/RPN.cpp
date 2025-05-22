/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:13:03 by pscala            #+#    #+#             */
/*   Updated: 2025/05/23 01:45:00 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN() : _stack()
{

}

RPN::RPN(const std::string &operation)
{
	parseOperation(operation);
	execOperation(operation);
}

RPN::RPN(const RPN &cpy) : _stack(cpy._stack)
{

}

RPN::~RPN()
{

}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

void RPN::execOperation(const std::string &operation)
{

	for (size_t i = 0; i < operation.length(); ++i)
	{
		if (operation[i] == ' ')
			continue;

		if (isOperand(operation[i]) && _stack.size() < 2)
			throw std::runtime_error("Error : not a valid RPN operation, operand on less than 2 numbers");

		if (isdigit(operation[i]))
			_stack.push(operation[i] - '0');

		if (isOperand(operation[i]) && _stack.size() > 1)
			calculate(operation[i]);
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error : not a valid RPN operation, 2 or more numbers left");
	std::cout << BOLD << GREEN << _stack.top() << RESET << std::endl;
}

void RPN::calculate(const char &operand)
{
	int number1;
	int number2;

	number2 = _stack.top();
	_stack.pop();
	number1 = _stack.top();
	_stack.pop();

	switch (operand)
	{
	case '+':
		_stack.push(number1 + number2);
		break;

	case '-':
		_stack.push(number1 - number2);
		break;

	case '*':
		_stack.push(number1 * number2);
		break;

	case '/':
		if (number2 == 0)
			throw std::runtime_error("Error : not a valid RPN operation, dividing by 0");
		_stack.push(number1 / number2);
		break;
	}
}


void parseOperation(const std::string &operation)
{
	if (operation.length() == 0)
		throw std::runtime_error("Error : no operation");

	for (size_t i = 0; i < operation.length(); ++i)
	{
		if (!isdigit(operation[i]) && operation[i] != '+' && operation[i] != '-'
			&& operation[i] != '*' && operation[i] != '/' && operation[i] != ' ')

			throw std::runtime_error("Error : not a valid RPN operation, containing non valid characters");
	}
}

bool isOperand(const char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}
