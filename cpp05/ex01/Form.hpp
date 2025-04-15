/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:32:29 by pscala            #+#    #+#             */
/*   Updated: 2025/04/12 18:18:19 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _minimumGradeToSign;
	const int _minimumGradeToExec;

  public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExec);
	Form(const Form &cpy);
	Form &operator=(const Form &src);
	~Form();

	std::string	getName() const;
	bool getStatus() const;
	int getMinimumToSign() const;
	int getMinimumToExec() const;

	void beSigned(const Bureaucrat &Bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &Form);
