/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:34:08 by pscala            #+#    #+#             */
/*   Updated: 2025/07/08 08:08:58 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

class PmergeMe
{
  private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<std::pair<int, int>> _pairs;
	int _orphan;

	PmergeMe();

	template <typename Container>
	Container	RecursiveSort(const Container& values);

	template <typename Container>
	Container buildChainMax(const std::vector<std::pair<int, int> > &pairs);

	template <typename Container>
	void pairUp(const Container &container);

	template <typename Container>
	void fordJohnsonSort(const Container &container);


  public:
	PmergeMe(const std::vector<int> &numbers);
	~PmergeMe();
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &src);
	void sortAndMeasure();
};





//recursiveSort
template <typename Container>
Container PmergeMe::RecursiveSort(const Container& values)
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

//MaxSort
template <typename Container>
Container PmergeMe::buildChainMax(const std::vector<std::pair<int, int> > &pairs)
{
	Container maxValues;
	for (size_t i = 0; i < pairs.size(); ++i)
		maxValues.push_back(pairs[i].first);

	Container mainChain = RecursiveSort(maxValues);
	return (maxValues);
}

//Pairs
template <typename Container>
void PmergeMe::pairUp(const Container &container)
{
	_pairs.clear();
	_orphan = -1;

	typename Container::const_iterator it = container.begin();

	while (it != container.end())
	{
		int first = *it;
		++it;

		if (it == container.end())
		{
			_orphan = first;
			break;
		}

		int second = *it;

		_pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
		++it;
	}
}

//Ford.JSON
template <typename Container>
void PmergeMe::fordJohnsonSort(const Container &container)
{
	// std::sort(container.begin(), container.end());
	pairUp(container);
	Container mainChain = buildChainMax<Container>(_pairs);
}
