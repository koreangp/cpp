/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:05:11 by pscala            #+#    #+#             */
/*   Updated: 2025/01/17 10:57:31 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once



#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <Colors.hpp>

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact();

	void display() const;
	void displayContact(int index) const;
	bool creat_contact();
	bool check_string(std::string string, bool number);
};
