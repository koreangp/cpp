/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:24:57 by pscala            #+#    #+#             */
/*   Updated: 2025/02/05 15:09:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y()
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
}

Point::~Point()
{
}

float Point::getXvalue() const
{
	return (x.toFloat());
}

float Point::getYvalue() const
{
	return (y.toFloat());
}

Point &Point::operator=(const Point &src)
{
	(void) src;
	return *this;
}
