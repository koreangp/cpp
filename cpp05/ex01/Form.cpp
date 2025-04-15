/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:32:33 by pscala            #+#    #+#             */
/*   Updated: 2025/04/12 18:30:04 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("JoJoForm"), _signed(false), _minimumGradeToSign(150), _minimumGradeToExec(1)
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(false), _minimumGradeToSign(gradeToSign), _minimumGradeToExec(gradeToExec)
{
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooLowException();

	if (gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToExec < 1)
		throw GradeTooLowException();
}

Form::Form(const Form &cpy) : _name(cpy._name), _signed(cpy._signed), _minimumGradeToSign(cpy._minimumGradeToSign), _minimumGradeToExec(cpy._minimumGradeToExec)
{
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_signed = src._signed;
	}
	return (*this);
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return (_name);
}

bool Form::getStatus() const
{
	return (_signed);
}

int Form::getMinimumToSign() const
{
	return (_minimumGradeToSign);
}

int Form::getMinimumToExec() const
{
	return (_minimumGradeToExec);
}

void Form::beSigned(const  Bureaucrat &Bureaucrat)
{

	if (Bureaucrat.getGrade() <= _minimumGradeToSign)
	{
		// std::cout << "Bureaucrat grade : " << Bureaucrat.getGrade() << " | Minimun grade to sign: " << _minimumGradeToSign << std::endl;
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << Form.getName() << "\n" << YELLOW
	<< "status : " << CYAN << Form.getStatus() << YELLOW
	<< "\n" << "minimum grade to sign the form : " << MAGENTA
	<< Form.getMinimumToSign() << "\n" << YELLOW
	<< "minimum grade to exec the form : " << MAGENTA
	<< Form.getMinimumToExec() << RESET;

	return (out);
}
