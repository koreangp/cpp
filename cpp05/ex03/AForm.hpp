/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:14:38 by pscala            #+#    #+#             */
/*   Updated: 2025/04/13 18:32:22 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Color.hpp"

class Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _minimumGradeToSign;
	const int _minimumGradeToExec;

  public:
	AForm();
	AForm(const std::string name, const int gradeToSign, const int gradeToExec);
	AForm(const AForm &cpy);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	std::string	getName() const;
	bool getStatus() const;
	int getMinimumToSign() const;
	int getMinimumToExec() const;

	void beSigned(const Bureaucrat &Bureaucrat);
	void execute(Bureaucrat const &executor) const;
	virtual void executeAction() const = 0;

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

	class FormIsNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
