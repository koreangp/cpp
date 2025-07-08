/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:39:53 by pscala            #+#    #+#             */
/*   Updated: 2025/07/08 07:29:03 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(const std::vector<int> &numbers) : _vector(numbers)
{
	std::deque<int> temp(numbers.begin(), numbers.end());
	_deque = temp;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &cpy) : _vector(cpy._vector), _deque(cpy._deque), _pairs(cpy._pairs), _orphan(cpy._orphan)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
		_pairs = src._pairs;
		_orphan = src._orphan;
	}
	return (*this);
}

void PmergeMe::sortAndMeasure()
{
	std::cout << BGREEN << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << GREEN << _vector[i] << " ";
	std::cout << RESET << std::endl;

	std::vector<int> vec = _vector;
	std::deque<int> deq = _deque;

	clock_t startVec = clock();
	this->fordJohnsonSort(vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	this->fordJohnsonSort(deq);
	clock_t endDeq = clock();

	std::cout << BBLUE << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << BLUE << vec[i] << " ";
	std::cout << RESET << '\n' << std::endl;


	double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
	double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << BGREEN << "Time to process a range of " << vec.size() << " elements with std::vector : " << GREEN << timeVec << " µs" << std::endl;
	std::cout << BBLUE << "Time to process a range of " << deq.size() << " elements with std::deque  : " << BLUE << timeDeq << " µs" << std::endl;
}

