/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:25:00 by pscala            #+#    #+#             */
/*   Updated: 2025/02/05 15:07:52 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Fixed.hpp"

class Point
{
  private:
	const Fixed x;
	const Fixed y;

  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	~Point();
	float getXvalue() const;
	float getYvalue() const;
	Point &operator=(const Point &src);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
