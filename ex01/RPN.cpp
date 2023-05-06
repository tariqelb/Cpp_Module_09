/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:47:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/05 20:30:56 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
}

Rpn::Rpn(const Rpn& rhs)
{
	*this = rhs;
}

Rpn&	Rpn::operator=(const Rpn& rhs)
{
	int						i;
	int						size;
	std::string 			val;
	std::stack<std::string>	tmp_expr;
	std::stack<std::string>	tmp2_expr;

	if (this != &rhs)
	{
		size = this->expr.size();
		i = 0;
		while (i < size)
		{
			this->expr.pop();
			i++;
		}
		tmp_expr = rhs.GetExpr();
		size = tmp_expr.size();
		i = 0;
		while (i < size)
		{
			val.assign(tmp_expr.top());
			tmp2_expr.push(val);
			tmp_expr.pop();
			i++;
		}
		size = tmp2_expr.size();
		i = 0;
		while (i < size)
		{
			val.assign(tmp2_expr.top());
			this->expr.push(val);
			tmp2_expr.pop();
			i++;
		}
	}
	return (*this);
}

Rpn::~Rpn()
{
}

std::stack<std::string>	Rpn::GetExpr(void) const
{
	return (this->expr);
}

void	Rpn::FillExpr(char	**arg)
{
	int 		i;
	int 		index;
	int			size;
	std::string expr;
	std::string	val;
	
	index = 1;
	while (arg[index])
	{
		expr = arg[index];
		size = expr.size();
		i = 0;
		while (i < size)
		{
			while (i < size && expr[i] == ' ')
				i++;
			if (i < size)
			{
				val = expr.substr(i, 1);
				this->expr.push(val);
				i++;
			}
		}
		index++;
	}
}

int	ValidDigit(std::string nbr)
{
	if (nbr.size() && nbr[0] >= '0' && nbr[0] <= '9')	
		return (0);
	return (1);
}

int	ValidOperator(std::string op)
{
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
	std::stack<std::string>	tmp_expr;

	i = 0;
	tmp_expr = GetExpr();
	size = tmp_expr.size();
	if (size < 3 || size % 2 == 0)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	i = 0;
	while (i < size)
	{
		std::string val;

		val = tmp_expr.top();
		if (ValidDigit(val) && ValidOperator(val))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		tmp_expr.pop();
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


void		FlipStack(std::stack<std::string>& flip_stack, std::stack<std::string> tmp_stack)
{
	while (tmp_stack.size())
	{
		flip_stack.push(tmp_stack.top());
		tmp_stack.pop();
	}
}

void	Operation(std::stack<int>& stack, std::string opr)
{
	int	nbr1;
	int nbr2;
	int rst;
	int size;

	size = stack.size();
	if (size < 2)
	{
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	nbr2 = stack.top();
	stack.pop();
	nbr1 = stack.top();
	stack.pop();
	if (opr == "+")
		rst = nbr1 + nbr2;
	if (opr == "-")
		rst = nbr1 - nbr2;
	if (opr == "*")
		rst = nbr1 * nbr2;
	if (opr == "/")
	{
		if (nbr2 == 0)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}	
		rst = nbr1 / nbr2;
	}
	//std::cout << "Rst :" << nbr1 << " " << nbr2 << " " << opr << " " << rst << std::endl;
	stack.push(rst);
}

void	Rpn::DisplayResult(void)
{
	int 					nbr;
	int 					opr;
	int 					size;
	std::string				data;
	std::stack<std::string> rev_stack;
	std::stack<int>			tmp_stack;

	FlipStack(rev_stack, this->GetExpr());
	size = rev_stack.size();
	nbr = 0;
	opr = 0;
	while (size)
	{
		data = rev_stack.top();
		if (ValidOperator(data))
		{
			tmp_stack.push(toInt(data));
			nbr++;
		}
		else
		{
			Operation(tmp_stack, data);
			nbr--;
		}
		rev_stack.pop();
		size--;
	}
	if (tmp_stack.size() != 1)
	{
		std::cerr << "Error :  " << tmp_stack.size() << std::endl;
		return;
	}
	std::cout << tmp_stack.top() << std::endl;
}
