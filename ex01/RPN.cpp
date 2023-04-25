/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:47:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/24 04:33:11 by tel-bouh         ###   ########.fr       */
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
	int						i;
	int						size;
	std::string 			val;
	std::list<std::string>	tmp_expr;

	if (this != &rhs)
	{
		tmp_expr = rhs.GetExpr();
		size = tmp_expr.size();
		if (size)
		{
			i = 0;
			while (i < size)
			{
				val.assign(tmp_expr.front());
				this->expr.push_back(val);
				tmp_expr.pop_front();
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

int	ValidDigit(std::string nbr)
{
	int i;
	int size;

	size = nbr.size();
	std::cout << "Nbr: " << nbr << " , Size: " << nbr.size() << std::endl;
	if (size && nbr[0] == '+' && size != 2)
		return (1);
	if (size && nbr[0] != '+' && nbr[0] != '-' && size != 1)
		return (1);
	i = 0;
	if (nbr[0] == '-')
		i++;
	while (i < size)
	{
		if (isdigit(nbr[i]))
			i++;
		else
			return (1);
	}
	if (i == size)
		return (0);
	return (1);
}

int	ValidOperator(std::string op)
{
	std::cout << "Op: " << op << " , Size: " << op.size() << std::endl;
	if (op.size() != 1)
		return (1);
	if (op[0] == '/' || op[0] == '*' ||op[0] == '+' || op[0] == '-')
		return (0);
	return (1);
}

int	Rpn::CheckForErrors(void)
{
	int						i;
	int						size;
	std::list<std::string>	tmp_expr;

	i = 0;
	tmp_expr = GetExpr();
	size = tmp_expr.size();
	if (size < 3 || size % 2 == 0)
	{
		std::cerr << "Error: unvalid number of arguments" << std::endl;
		return (1);
	}
	i = 0;
	while (i < size)
	{
		if (i == 0 || i == 1 || (i % 2))
		{
			if (ValidDigit(tmp_expr.front()))
			{
				std::cerr << "Error: invalid number." << std::endl;
				return (1);
			}
			tmp_expr.pop_front();
		}
		else
		{
			if (ValidOperator(tmp_expr.front()))
			{
				std::cerr << "Error: invalid operator." << std::endl;
				return (1);
			}
			tmp_expr.pop_front();
		}
		i++;
	}
	return (0);
}

int	toInt(std::string nbr)
{
	int i;
	int rst;
	int size;
	int	sign;

	
	i = 0;
	rst = 0;
	sign = 1;
	size = nbr.size();
	if (size && (nbr[0] == '-' || nbr[0] == '+'))
	{
		if (nbr[0] == '-')
			sign = -1;
		i++;
	}
	while (i < size)
	{
		rst = rst * 10;
		rst = rst + (nbr[i] - 48);
		i++;
	}
	return (rst * sign);
}

void	Rpn::DisplayResult(void)
{
	std::cout << "DisplayResult member function called" << std::endl;
	int 					i;
	int 					size;
	int						val;
	int						rst;
	std::list<std::string> tmp_expr;
	std::list<std::string> nbr;
	std::list<std::string> opr;

	tmp_expr = GetExpr();
	size = tmp_expr.size();
	i = 0;
	while (i < size)
	{
		if (i == 0 || i == 1 || (i % 2))
			nbr.push_back(tmp_expr.front());
		else
			opr.push_back(tmp_expr.front());
		tmp_expr.pop_front();
		i++;
	}
	rst = toInt(nbr.front());
	nbr.pop_front();
	size = opr.size();
	i = 0;
	while (i < size)
	{
		val = toInt(nbr.front());
		nbr.pop_front();
		std::cout << "Operation : " << rst << " " << val << std::endl;
		if (opr.front() == "-")
			rst = rst - val;
		else if (opr.front() == "+")
			rst = rst + val;
		else if (opr.front() == "*")
			rst = rst * val;
		else if (opr.front() == "/")
			rst = rst / val;
		opr.pop_front();
		i++;
	}
	
	std::cout << "Result: " << rst << "." << std::endl;
	/*while (i < size)
	{
		std::cout << "Value : [" << this->expr.front() << "]." << std::endl;
		this->expr.pop_front();
		i++;
	}
	i = 0;
	size = nbr.size();
	while (i < size)
	{
		std::cout << "nbr : " << nbr.front() << std::endl;
		nbr.pop_front();
		i++;
	}
	i = 0;
	size = opr.size();
	while (i < size)
	{
		std::cout << "Opr : " << opr.front() << std::endl;
		opr.pop_front();
		i++;
	}*/
}

std::list<std::string>	Rpn::GetExpr(void)
{
	return (this->expr);
}

