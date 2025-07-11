/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 00:39:53 by pscala            #+#    #+#             */
/*   Updated: 2025/07/11 06:35:11 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &numbers) : _vector(numbers), _flag(-1)
{
	std::deque<int> temp(numbers.begin(), numbers.end());
	_deque = temp;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy) : _vector(cpy._vector),
	_deque(cpy._deque), _pairs(cpy._pairs), _incel(cpy._incel)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
		_pairs = src._pairs;
		_incel = src._incel;
	}
	return (*this);
}

void PmergeMe::generateJacobsthal(size_t &size)
{
	_jacob.clear();

	std::vector<size_t> seq;

	if (size < 2)
		return;

	seq.push_back(1);
	seq.push_back(3);
	for (size_t i = 2; ; ++i)
	{
		size_t val = seq[i - 1] + 2 * seq[i - 2];
		if (val >= size)
			break;
		seq.push_back(val);
	}

	std::vector<bool> seen(size, false);
	for (int i = seq.size() - 1; i >= 0; --i)
	{
		if (seq[i] < size)
		{
			_jacob.push_back(seq[i]);
			seen[seq[i]] = true;
		}
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (!seen[i] && i != 0)
			_jacob.push_back(i);
	}

}


void PmergeMe::sortAndMeasure()
{
	clock_t	startVec;
	clock_t	endVec;
	clock_t	startDeq;
	clock_t	endDeq;
	double	timeVec;
	double	timeDeq;

	std::cout << BGREEN << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << GREEN << _vector[i] << " ";
	std::cout << RESET << std::endl;

	std::vector<int> vec = _vector;
	startVec = clock();
	this->fordJohnSort(vec);
	endVec = clock();

	std::deque<int> deq = _deque;
	startDeq = clock();
	this->fordJohnSort(deq);
	endDeq = clock();

	std::cout << BBLUE << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << BLUE << vec[i] << " ";
	std::cout << RESET << '\n' << std::endl;

	timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
	timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << BGREEN << "Time to process a range of " << vec.size() << " elements with vector : " << GREEN << timeVec << " µs" << std::endl;
	std::cout << BBLUE << "Time to process a range of " << deq.size() << " elements with deque  : " << BLUE << timeDeq << " µs" << std::endl;
}
