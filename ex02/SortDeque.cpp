/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDeque.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:57:09 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/06 17:35:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	DeqInsertion(std::deque<std::deque<unsigned int> >& merge, std::deque<unsigned int> left, std::deque<unsigned int> right)
{
	std::deque<unsigned int>	insert;
	int							r_size;
	int							l_size;
	int							i;
	int							j;

	l_size = left.size();
	r_size = right.size();
	i = 0;
	j = 0;
	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			insert.push_back(left[i]);
			i++;
		}
		else
		{
			insert.push_back(right[j]);
			j++;
		}
	}
	while (i < l_size)
	{
		insert.push_back(left[i]);
		i++;
	}
	while (j < r_size)
	{
		insert.push_back(right[j]);
		j++;
	}
	size_t ii = 0;
	std::cout << "Left : ";
	while (ii < left.size())
	{
		std::cout << left[ii] << " ," ;
		ii++;
	}
	std::cout << std::endl;
	ii = 0;
	std::cout << "Right : ";
	while (ii < right.size())
	{
		std::cout << right[ii] << " ," ;
		ii++;
	}
	std::cout << std::endl;
	ii = 0;
	std::cout << "Insert : ";
	while (ii < insert.size())
	{
		std::cout << insert[ii] << " ," ;
		ii++;
	}
	std::cout << std::endl;
	if (merge.size() >= 2)
		merge.erase(merge.begin(), merge.begin() + 2);
	merge.push_back(insert);
}

void	SortDeq(std::deque<unsigned int>& deq)
{
	int				i;
	int 			size;
	unsigned int	tmp;

	i = 0;
	size = deq.size();
	while (i < size - 1)
	{
		if (deq[i] > deq[i + 1])
		{
			tmp = deq[i];
			deq[i] = deq[i + 1];
			deq[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	DequeInsertionSort(std::deque<unsigned int>& deq, std::deque<std::deque<unsigned int> > merge)
{
	int				i;
	int				j;
	int				size;

	size = merge.size();
	i = 0;
	while (i < size)
	{
		SortDeq(merge[i]);
		i++;
	}
	while (size != 1)
	{
		i = 0;
		j = i + 1;
		if (j < size)
			DeqInsertion(merge, merge[i], merge[j]);
		i++;
		size = merge.size();
	}
	deq.assign(merge[0].begin(), merge[0].end());
}

void	DequeMergeSort(std::deque<unsigned int>& deq, std::deque<std::deque<unsigned int> >& merge, int div)
{
	int size;
	int	mid;
	std::deque<unsigned int> 	left_chunk;
	std::deque<unsigned int> 	right_chunk;

	size = deq.size();
	if (size > div)
	{
		mid = size / 2;
		left_chunk.assign(deq.begin(), deq.begin() + mid);
		right_chunk.assign(deq.begin() + mid, deq.end());
		DequeMergeSort(left_chunk, merge, div);
		DequeMergeSort(right_chunk, merge, div);
	}
	else
		merge.push_back(deq);
}

void	SortDeque(std::deque<unsigned int>& deq)
{
	int div;
	int size;
	std::deque<std::deque<unsigned int> > merge;

	size = deq.size();
	if (size == 1)
		return;
	if (size < 10)
		div = 2;
	else if (size < 100)
		div = 10;
	else
		div = 20;
	DequeMergeSort(deq, merge, div);
	DequeInsertionSort(deq, merge);
}


