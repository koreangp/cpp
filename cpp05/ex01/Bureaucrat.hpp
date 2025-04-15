/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:29 by pscala            #+#    #+#             */
/*   Updated: 2025/04/12 17:45:07 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"
#include "Form.hpp"

class Bureaucrat
{
  private:
	std::string _name;
	int _grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &src);

	std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();
	void signForm(Form &Form);

	class GradeTooHighExeption : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowExeption : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
