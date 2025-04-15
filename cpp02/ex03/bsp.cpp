/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:24:50 by pscala            #+#    #+#             */
/*   Updated: 2025/02/05 14:59:39 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ABP = (b.getXvalue() - a.getXvalue()) * (point.getYvalue() - a.getYvalue()) -
				(b.getYvalue() - a .getYvalue()) * (point.getXvalue() - a.getXvalue());

	Fixed BCP = (c.getXvalue() - b.getXvalue()) * (point.getYvalue() - b.getYvalue()) -
				(c.getYvalue() - b.getYvalue()) * (point.getXvalue() - b.getXvalue());

	Fixed CAP = (a.getXvalue() - c.getXvalue()) * (point.getYvalue() - c.getYvalue()) -
				(a.getYvalue() - c.getYvalue()) * (point.getXvalue() - c.getXvalue());

	return (ABP > 0 && BCP > 0 && CAP > 0) || (ABP < 0 && BCP < 0 && CAP < 0);
}
