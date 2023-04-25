/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:39:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/25 12:06:08 by tel-bouh         ###   ########.fr       */
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
	int 				i;
	int 				size;
	std::vector<int>	vec;
	std::deque<int>		deq;
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

std::vector<int>&	PmergeMe::GetVectorNumbers(void)
{
	return (this->vec_nbr);
}

std::deque<int>&	PmergeMe::GetDequeNumbers(void)
{
	return (this->deq_nbr);
}

int	CheckForErrors(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[j])
		{

		}
		i++;
	}
	return (0);
}
