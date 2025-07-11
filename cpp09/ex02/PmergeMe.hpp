/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:34:08 by pscala            #+#    #+#             */
/*   Updated: 2025/07/11 06:44:58 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

class PmergeMe
{
  public:
	PmergeMe(const std::vector<int> &numbers);
	~PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &src);
	void sortAndMeasure();

  private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<size_t> _jacob;
	std::vector<std::pair<int, int> > _pairs;
	std::vector<std::pair<int, size_t> > _maxPosInMainChain;

	int _incel;
	int _flag;

	PmergeMe();
	void generateJacobsthal(size_t &size);

	template <typename Container>
	void insertIncel(Container &mainChain);

	template <typename Container>
	void insertMinInMain(Container &mainChain);

	template <typename Container>
	Container	RecursiveSort(const Container &values);

	template <typename Container>
	Container SortMax();

	template <typename Container>
	void pairUp(const Container &container);

	template <typename Container>
	void fordJohnSort(Container &container);
};



//insertIncel
template <typename Container>
void PmergeMe::insertIncel(Container &mainChain)
{
	if (_incel != -1)
	{
		typename Container::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), _incel);
		mainChain.insert(insertPos, _incel);
	}
}


//insertMinInMain
template <typename Container>
void PmergeMe::insertMinInMain(Container &mainChain)
{
	size_t size = _pairs.size();
	if (size == 1)
	{
		typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), _pairs[0].second);
		mainChain.insert(pos, _pairs[0].second);
		insertIncel(mainChain);
		return;
	}

	generateJacobsthal(size);

	int minZero = _pairs[0].second;
	typename Container::iterator maxItZero = std::find(mainChain.begin(), mainChain.end(), _pairs[0].first);
	typename Container::iterator insertPosZero = std::lower_bound(mainChain.begin(), maxItZero, minZero);
	mainChain.insert(insertPosZero, minZero);

	for (size_t i = 0; i < _jacob.size(); ++i)
	{
		size_t minIndex = _jacob[i];
		int minToInsert = _pairs[minIndex].second;

		typename Container::iterator maxIt = std::find(mainChain.begin(), mainChain.end(), _pairs[minIndex].first);
		typename Container::iterator insertPos = std::lower_bound(mainChain.begin(), maxIt, minToInsert);

		mainChain.insert(insertPos, minToInsert);
	}

	insertIncel(mainChain);
}

//recursiveSort
template <typename Container>
Container PmergeMe::RecursiveSort(const Container &values)
{
	if (values.size() <= 1)
		return values;

	typename Container::const_iterator mid = values.begin() + values.size() / 2;

	Container left(values.begin(), mid);
	Container right(mid, values.end());

	Container sortedLeft = RecursiveSort(left);
	Container sortedRight = RecursiveSort(right);


	for (typename Container::const_iterator it = sortedRight.begin(); it != sortedRight.end(); ++it)
	{
		typename Container::iterator pos = std::lower_bound(sortedLeft.begin(), sortedLeft.end(), *it);
		sortedLeft.insert(pos, *it);
	}

	return sortedLeft;
}

//SortMax
template <typename Container>
Container PmergeMe::SortMax()
{
	Container sortedMax;
	for (size_t i = 0; i < _pairs.size(); ++i)
		sortedMax.push_back(_pairs[i].first);

	Container mainChain = RecursiveSort(sortedMax);

	for (size_t i = 0; i < _pairs.size(); ++i)
	{
		int min = _pairs[i].second;
		int max = _pairs[i].first;

		typename Container::iterator pos = std::find(mainChain.begin(), mainChain.end(), max);
		if (pos != mainChain.end())
		{
			size_t index = std::distance(mainChain.begin(), pos);
			_maxPosInMainChain.push_back(std::make_pair(min, index));
		}
	}

	return (mainChain);
}

//Pairs
template <typename Container>
void PmergeMe::pairUp(const Container &container)
{
	_pairs.clear();
	_incel = -1;

	typename Container::const_iterator it = container.begin();

	while (it != container.end())
	{
		int first = *it;
		++it;

		if (it == container.end())
		{
			_incel = first;
			break;
		}

		int second = *it;

		_pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
		++it;
	}
}

//FordJSON
template <typename Container>
void PmergeMe::fordJohnSort(Container &mainChain)
{
	// std::sort(mainChain.begin(), mainChain.end());
	pairUp(mainChain);
	mainChain = SortMax<Container>();


	// if (_flag == -1)
	// {
	// 	int i = 0;
	// 	for (typename Container::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
	// 	{
    //     	std::cout << BCYAN << "maxChain index: " << i << " value: " << *it << " " << RESET << std::endl;
	// 		++i;
	// 	}


	insertMinInMain(mainChain);


	// if (_jacob.size() != 0)
	// {
	// 	std::cout << BYELLOW << "Jacob : ";
	// 	for (std::vector<size_t>::iterator it = _jacob.begin(); it != _jacob.end(); ++it)
	// 		std::cout << *it << " ";
	// 	std::cout << std::endl;
	// }
	// else
	// 	std::cout << BRED << "no jacob" << std::endl;
}
