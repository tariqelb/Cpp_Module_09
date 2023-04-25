/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:39:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/25 14:52:40 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "Default constructer called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe& rhs)
{
	std::cout << "Copy constructer called" << std::endl;
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(PmergeMe& rhs)
{
	int 						i;
	int 						size;
	std::vector<unsigned int>	vec;
	std::deque<unsigned int>	deq;

	std::cout << "Copy assinement operator called" << std::endl;
	if (this != &rhs)
	{
		vec = rhs.GetVectorNumbers();
		size = vec.size();
		i = 0;
		while (i < size)
		{
			this->vec_nbr.push_back(vec[i]);
			i++;
		}
		deq = rhs.GetDequeNumbers();
		size = deq.size();
		i = 0;
		while (i < size)
		{
			this->deq_nbr.push_back(deq[i]);
			i++;
		}
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "Destructer called" << std::endl;
}

std::vector<unsigned int>&	PmergeMe::GetVectorNumbers(void)
{
	return (this->vec_nbr);
}

std::deque<unsigned int>&	PmergeMe::GetDequeNumbers(void)
{
	return (this->deq_nbr);
}

int	IsPositveNumber(std::string val)
{
	int i;
	int size;

	i = 0;
	size = val.size();
	if (size == 0 || val[0] == '-')
		return (1);
	if (val[0] == '+')
		i++;
	while (i < size)
	{
		if (val[i] >= '0' && val[i] <= '9')
			i++;
		else
			return (1);
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

int	PmergeMe::CheckForErrors(int ac, char **av)
{
	int			i;
	int			j;
	int			k;
	int			size;
	int			nbr;
	std::string	arg;
	std::string	val;

	i = 1;
	while (i < ac)
	{
		j = 0;
		arg.assign(av[i]);
		size = arg.size();
		while (j < size)
		{
			while (j < size && (arg[j] == ' ' || arg[j] == '\t'))
				j++;
			k = 0;
			while (j + k < size && (arg[j + k] != ' ' && arg[j + k] != '\t'))
				k++;
			if (k)
			{
				val.assign(arg.substr(j, k));
				if (IsPositveNumber(val) == 0)
				{
					this->vec_nbr.push_back(toInt(val));
					this->deq_nbr.push_back(toInt(val));
				}
			}
			j = j + k;
		}
		i++;
	}
	return (0);
}

void	PmergeMe::FillContainers(int ac, char **av)
{
	(void) ac;
	(void) av;
	std::cout << "FillContainers called" << std::endl;
}

void	PmergeMe::DisplaySortedResult(void)
{
	int i;
	int size;
	std::cout << "DisplaySortedResult called" << std::endl;
	
	i = 0;
	size = this->vec_nbr.size();
	std::cout << "Vector : " ;
	while (i < size)
	{
		std::cout << this->vec_nbr[i] << ", ";
		i++;
	}
	std::cout << std::endl;
	i = 0;
	size = this->deq_nbr.size();
	std::cout << "Deque : " ;
	while (i < size)
	{
		std::cout << this->deq_nbr[i] << ", ";
		i++;
	}
	std::cout << std::endl;
}



