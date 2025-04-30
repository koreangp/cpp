/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:56 by pscala            #+#    #+#             */
/*   Updated: 2025/04/30 03:55:31 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << BOLD << GREEN << "Mutant stack" << RESET << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << BOLD << "top element of the stack (last added): " << BLUE << mstack.top() << RESET << std::endl;
	mstack.pop();
	std::cout << BOLD << "number of element of the stack: " << BLUE << mstack.size() << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << BOLD << "element of the stack: " << BLUE << *it << RESET << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << BOLD << "number of element of the copied stack : " << BLUE << s.size() << RESET << std::endl;


	std::cout << std::endl;
	std::cout << BOLD << GREEN << "Comparison with container type list" << RESET << std::endl;

	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << BOLD << "last element of the list: " << YELLOW << lstack.back() << RESET << std::endl;
	lstack.pop_back();
	std::cout << BOLD << "number of element of the list: " << YELLOW << lstack.size() << RESET << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << BOLD << "element of the list: " << YELLOW << *lit << RESET << std::endl;
		++lit;
	}
	std::list<int> l(lstack);
	std::cout << BOLD << "number of element of the copied list : " << YELLOW << l.size() << RESET << std::endl;
	return (0);
}
