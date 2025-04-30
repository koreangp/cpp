/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 03:00:19 by pscala            #+#    #+#             */
/*   Updated: 2025/04/30 03:55:46 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& cpy)
{
	*this = cpy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

