/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:14:33 by pscala            #+#    #+#             */
/*   Updated: 2025/04/13 16:26:38 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _minimumGradeToSign(150), _minimumGradeToExec(1)
{
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(false), _minimumGradeToSign(gradeToSign), _minimumGradeToExec(gradeToExec)
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

AForm::AForm(const AForm &cpy) : _name(cpy._name), _signed(cpy._signed), _minimumGradeToSign(cpy._minimumGradeToSign), _minimumGradeToExec(cpy._minimumGradeToExec)
{
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_signed = src._signed;
	}
	return (*this);
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return (_name);
}

bool AForm::getStatus() const
{
	return (_signed);
}

int AForm::getMinimumToSign() const
{
	return (_minimumGradeToSign);
}

int AForm::getMinimumToExec() const
{
	return (_minimumGradeToExec);
}

void AForm::beSigned(const  Bureaucrat &Bureaucrat)
{

	if (Bureaucrat.getGrade() <= _minimumGradeToSign)
	{
		// std::cout << "Bureaucrat grade : " << Bureaucrat.getGrade() << " | Minimun grade to sign: " << _minimumGradeToSign << std::endl;
		_signed = true;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw FormIsNotSignedException();
	if (executor.getGrade() > _minimumGradeToExec)
		throw GradeTooLowException();
	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char*	AForm::FormIsNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << "\n" << YELLOW
	<< "status : " << CYAN << AForm.getStatus() << YELLOW
	<< "\n" << "minimum grade to sign the form : " << MAGENTA
	<< AForm.getMinimumToSign() << "\n" << YELLOW
	<< "minimum grade to exec the form : " << MAGENTA
	<< AForm.getMinimumToExec() << RESET;

	return (out);
}
