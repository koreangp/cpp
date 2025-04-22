/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:57:01 by pscala            #+#    #+#             */
/*   Updated: 2025/04/22 20:03:35 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
	std::srand(std::time(0));
	int n = std::rand() % 3;
	if (!n)
	{
		return (new A);
	}
	if (n == 1)
	{
		return (new C);
	}
	if (n == 2)
	{
		return (new B);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << BOLD << "object ptr type is " << BLUE << "A" << RESET << std::endl;
		return;
	}

	if (dynamic_cast<B*>(p))
	{
		std::cout << BOLD << "object ptr type is " << YELLOW << "B" << RESET << std::endl;
		return;
	}

	if (dynamic_cast<C*>(p))
	{
		std::cout << BOLD << "object ptr type is " << MAGENTA << "C" << RESET << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A &ref = dynamic_cast<A&>(p);
		std::cout << BOLD << "object ref type is " << BLUE << "A" << RESET << std::endl;
		(void) ref;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "";
	}

	try
	{
		B &ref = dynamic_cast<B&>(p);
		std::cout << BOLD << "object ref type is " << YELLOW << "B" << RESET << std::endl;
		(void) ref;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "";
	}

	try
	{
		C &ref = dynamic_cast<C&>(p);
		std::cout << BOLD << "object ref type is " << MAGENTA << "C" << RESET << std::endl;
		(void) ref;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "";
	}
	return;
}

int main()
{
	Base *a = new A;
	Base *b = new B;
	Base *c = new C;
	Base *r = generate();

	std::cout << BOLD << BLUE << "a " << WHITE << ": " << RESET;
	identify(a);
	std::cout << BOLD << BLUE << "a " << WHITE << ": " << RESET;
	identify(*a);

	std::cout << BOLD << YELLOW << "b " << WHITE << ": " << RESET;
	identify(b);
	std::cout << BOLD << YELLOW << "b " << WHITE << ": " << RESET;
	identify(*b);

	std::cout << BOLD << MAGENTA << "c " << WHITE << ": " << RESET;
	identify(c);
	std::cout << BOLD << MAGENTA << "c " << WHITE << ": " << RESET;
	identify(*c);

	std::cout << BOLD << "r : " << RESET;
	identify(r);
	std::cout << BOLD << "r : " << RESET;
	identify(*r);

	delete a;
	delete b;
	delete c;
	delete r;

	return (0);
}
