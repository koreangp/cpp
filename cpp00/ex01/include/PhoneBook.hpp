/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:05:08 by pscala            #+#    #+#             */
/*   Updated: 2025/01/29 14:37:20 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once



#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact MyLittlePhoneBook[8];
	int contactCount;
	int overwrite;

  public:
	PhoneBook();

	bool addContact();
	bool searchContact();

};

