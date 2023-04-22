/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:47:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/22 01:22:55 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
	std::cout << "Default Constructer called" << std::endl;
}

Rpn::Rpn(Rpn& rhs)
{
	std::cout << "Copy constructer called" << std::endl;
	*this = rhs;
}

Rpn&	Rpn::operator=(Rpn& rhs)
{
	int			i;
	int			size;
	std::string val;

	if (this != &rhs)
	{
		size = rhs.Size();
		if (size)
		{
			i = 0;
			while (i < size)
			{
				val.assign(rhs.Front());
				this->expr.push_back(val);
				rhs.PopFront();
				rhs.PushBack(val);
				i++;
			}
		}
	}
	return (*this);
}

Rpn::~Rpn()
{
	std::cout << "Destructer Called" << std::endl;
}

void	Rpn::FillExpr(char	*arg)
{
	int 		i;
	int 		j;
	int			size;
	std::string expr;
	std::string	val;

	std::cout << "FillExpr member function called" << std::endl;
	if (arg == NULL)
		return ;
	expr = arg;
	size = expr.size();
	i = 0;
	while (i < size)
	{
		while (i < size && expr[i] == ' ')
			i++;
		j = 0;
		while (i + j < size && arg[i + j] != ' ')
			j++;
		if (j)
		{
			val = expr.substr(i, j);
			this->expr.push_back(val);
		}
		i = i + j;
	}
}

void	Rpn::DisplayResult(void)
{
	std::cout << "DisplayResult member function called" << std::endl;
	int i;
	int size;

	i = 0;
	size = this->expr.size();
	while (i < size)
	{
		std::cout << "Value : [" << this->expr.front() << "]." << std::endl;
		this->expr.pop_front();
		i++;
	}
}

int	Rpn::Size(void)
{
	return (expr.size());
}

void	Rpn::PushFront(std::string& val)
{
	this->expr.push_front(val);
}

void	Rpn::PushBack(std::string& val)
{
	this->expr.push_back(val);
}

void	Rpn::PopFront(void)
{
	this->expr.pop_front();
}

void	Rpn::PopBack(void)
{
	this->expr.pop_back();
}

std::string&	Rpn::Front(void)
{
	return (this->expr.front());
}
