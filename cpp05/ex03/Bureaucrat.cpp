/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:44:27 by pscala            #+#    #+#             */
/*   Updated: 2025/04/13 18:43:26 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("JoJo"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade <= 0)
		throw GradeTooHighExeption();
	if (grade >= 151)
		throw GradeTooLowExeption();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		_name = src._name;
		_grade = src._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighExeption();
	_grade--;
}

void	Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowExeption();
	_grade++;
}

void Bureaucrat::signForm(AForm &Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << BOLD << BLUE << _name << GREEN << " signed " << YELLOW << Form.getName() << RESET << std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr << BOLD << BLUE << _name << RED << " couldn't sign " << YELLOW << Form.getName() << " because : " << RED << e.what() << RESET << std::endl;
	}
}


void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << BOLD << BLUE << _name << CYAN <<  " executed " << YELLOW
		<< form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << BLUE << _name << RED << " could not execute the form "
		<< YELLOW << form.getName() << RED << " because " << e.what() << RESET << std::endl;
	}
}



const	char* Bureaucrat::GradeTooHighExeption::what() const throw()
{
	return "Grade is too high!";
}

const	char* Bureaucrat::GradeTooLowExeption::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade: " << MAGENTA << bureaucrat.getGrade() << RESET;
	return (out);
}
