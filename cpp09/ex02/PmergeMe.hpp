/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:34:08 by pscala            #+#    #+#             */
/*   Updated: 2025/07/10 09:07:44 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

class PmergeMe
{
  private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	std::vector<std::pair<int, int> > _pairs;
	std::vector<std::pair<int, size_t> > _maxPosInMainChain;
	int _incel;

	PmergeMe();

	template <typename Container>
	Container	RecursiveSort(const Container& values);

	template <typename Container>
	Container SortMax();

	template <typename Container>
	void pairUp(const Container &container);

	template <typename Container>
	void fordJohnsonSort(Container &container);


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

//SortMax
template <typename Container>
Container PmergeMe::SortMax()
{
	Container sortedMax;
	for (size_t i = 0; i < _pairs.size(); ++i)
		sortedMax.push_back(pairs[i].first);

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

	return (sortedMax);
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
void PmergeMe::fordJohnsonSort(Container &mainChain)
{
	// std::sort(container.begin(), container.end());
	pairUp(mainChain);
	mainChain = SortMax<Container>();

}
