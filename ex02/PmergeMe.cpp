/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:39:16 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/26 13:53:20 by tel-bouh         ###   ########.fr       */
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

int	PmergeMe::FillAndCheckForErrors(int ac, char **av)
{
	int			i;
	int			j;
	int			k;
	int			size;
	int			nbr;
	std::string	arg;
	std::string	val;
	
	std::cout << "FillAndCheckForErrors called" << std::endl; 
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


void	VectorInsertionSort(std::vector<unsigned int>& vec)
{
	int				i;
	int				j;
	int				size;
	unsigned int	tmp;

	size = vec.size();
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (vec[i] > vec[j])
		{
			tmp = vec[i];
			vec[i] = vec[j];
			vec[j] = tmp;
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

std::vector<unsigned int>	MergeInsertion(std::vector<unsigned int> tmp1, std::vector<unsigned int> tmp2)
{
	int							i;
	int							j;
	int 						size_i;
	int 						size_j;
	std::vector<unsigned int>	merge;
	i = 0;
	j = 0;
	size_i = tmp1.size();
	size_j = tmp2.size();
	while (i < size_i || j < size_j)
	{
		if (i == size_i && j < size_j)
		{
			while (j < size_j)
			{
				merge.push_back(tmp2[j]);
				j++;
			}
		}
		else if (j == size_j && i < size_i)
		{
			while (i < size_i)
			{
				merge.push_back(tmp1[i]);
				i++;
			}
		}
		else if (tmp1[i] <= tmp2[j])
		{
			merge.push_back(tmp1[i]);
			i++;
		}
		else if (tmp1[i] > tmp2[j])
		{
			merge.push_back(tmp2[j]);
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (merge);
}

void	VectorMergeSort(std::vector<unsigned int>& vec, std::vector<unsigned int> *tmp, int div)
{
	int i;
	int j;
	int	size;
	
	while (div > 1)
	{
		i = 0;
		j = 0;
		while (i < div)
		{
			tmp[j] = MergeInsertion(tmp[i], tmp[i + 1]);
			j++;
			i = i + 2;
		}
		div = div / 2;
	}
	vec = tmp[0];
}

void	SortVector(std::vector<unsigned int>& vec)
{
	int i;
	int j;
	int div;
	int size;
	int	chunks;

	if (size == 1)
		return;
	size = vec.size();
	if (size < 10)
		div = 2;
	else if (size < 100)
		div = 4;
	else if (size < 500)
		div = 8;
	else
		div = 16;
	std::vector<unsigned int> tmp[div];
	i = 0;
	j = 0;
	chunks = size / div;
	if (size % 2)
		chunks += 1;
	while (i < div)
	{
		while (j < size && j < (chunks * (i + 1)))
		{
			tmp[i].push_back(vec[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < div)
	{
		VectorInsertionSort(tmp[i]);
		i++;
	}
	i = 0;
	/*while (i < div)
	{
		j = 0;
		size = tmp[i].size();
		std::cout << "Temp: ";
		while (j < size)
		{
			std::cout << tmp[i][j];
			j++;
			if (j < size)
				std::cout << " ";
			else
				std::cout << std::endl;
		}
		i++;
	}*/
	VectorMergeSort(vec, tmp, div);
}

void	PmergeMe::SortAndDisplayResult(void)
{
	int 			i;
	int 			size;
	std::time_t		vector_time_be;
	std::time_t		vector_time_af;
	std::time_t		deque_time_be;
	std::time_t		deque_time_af;

	std::cout << "SortAndDisplayResult called" << std::endl;
	
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
	vector_time_be = std::time(NULL);
	SortVector(this->vec_nbr);
	vector_time_af = std::time(NULL);
	deque_time_be = std::time(NULL);
	//sortDeque(this->deq_nbr);
	deque_time_af = std::time(NULL);
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
	std::cout << "Time to process a range of " << this->vec_nbr.size() << " elements with std::vector : ";
	std::cout << (vector_time_af - vector_time_be) << " us" << std::endl; 
	std::cout << "Time to process a range of " << this->deq_nbr.size() << " elements with std::deque  : ";
	std::cout << (deque_time_af - deque_time_be) << " us" << std::endl; 
}



