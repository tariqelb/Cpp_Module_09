/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:39:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/27 19:17:59 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	int 						i;
	int 						size;
	std::vector<unsigned int>	vec;
	std::deque<unsigned int>	deq;

	if (this != &rhs)
	{
		size = this->vec_nbr.size();
		if (size)
		{
			this->vec_nbr.pop_back();
			size--;
		}
		size = this->deq_nbr.size();
		if (size)
		{
			this->deq_nbr.pop_back();
			size--;
		}
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
}

const std::vector<unsigned int>&	PmergeMe::GetVectorNumbers(void) const
{
	return (this->vec_nbr);
}

const std::deque<unsigned int>&	PmergeMe::GetDequeNumbers(void) const
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

int	PmergeMe::FillAndCheckForErrors(int ac, char **av)
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
				else
					return (1);
			}
			j = j + k;
		}
		i++;
	}
	return (0);
}

void	PmergeMe::SortAndDisplayResult(void)
{
	int 			i;
	int 			size;
	struct timeval	vec_time_be;
	struct timeval	vec_time_af;
	struct timeval	deq_time_be;
	struct timeval	deq_time_af;
	
	i = 0;
	size = this->vec_nbr.size();
	std::cout << "Before: " ;
	while (i < size)
	{
		std::cout << this->vec_nbr[i];
		i++;
		if (i < size)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	gettimeofday(&vec_time_be, NULL);
	SortVector(this->vec_nbr);
	gettimeofday(&vec_time_af, NULL);
	gettimeofday(&deq_time_be, NULL);
	SortDeque(this->deq_nbr);
	gettimeofday(&deq_time_af, NULL);
	i = 0;
	std::cout << "after:  " ;
	while (i < size)
	{
		std::cout << this->vec_nbr[i];
		i++;
		if (i < size)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	i = 0;
	std::cout << "after:  " ;
	while (i < size)
	{
		std::cout << this->deq_nbr[i];
		i++;
		if (i < size)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << this->vec_nbr.size() << " elements with std::vector : ";
	std::cout << (vec_time_af.tv_sec - vec_time_be.tv_sec ) << ".";
   	std::cout << (vec_time_af.tv_usec - vec_time_be.tv_usec) << " us" << std::endl; 
	std::cout << "Time to process a range of " << this->deq_nbr.size() << " elements with std::deque  : ";
	std::cout << (deq_time_af.tv_sec - deq_time_be.tv_sec ) << ".";
   	std::cout << (deq_time_af.tv_usec - deq_time_be.tv_usec) << " us" << std::endl; 
}

void	PmergeMe::IsVectorSorted(void)
{
	int i;
	int size;

	size = this->vec_nbr.size();
	if (size == 0)
		std::cout << "Vector is empty." << std::endl;
	else
	{
		i = 0;
		while (i < size - 1)
		{
			if (this->vec_nbr[i] > this->vec_nbr[i + 1])
			{
				std::cout << "Vector is not sorted." << std::endl;
				return;
			}
			i++;
		}
		std::cout << "Vector is sorted." << std::endl;
	}
}

void	PmergeMe::IsDequeSorted(void)
{
	int i;
	int size;

	size = this->deq_nbr.size();
	if (size == 0)
		std::cout << "Deque is empty." << std::endl;
	else
	{
		i = 0;
		while (i < size - 1)
		{
			if (this->deq_nbr[i] > this->deq_nbr[i + 1])
			{
				std::cout << "Deque is not sorted." << std::endl;
				return;
			}
			i++;
		}
		std::cout << "Deque is sorted." << std::endl;
	}
}
