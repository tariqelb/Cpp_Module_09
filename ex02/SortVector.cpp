/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:55:32 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/24 17:17:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	VecInsertion(std::vector<std::vector<unsigned int> >& merge, std::vector<unsigned int> left, std::vector<unsigned int> right)
{
	std::vector<unsigned int>	insert;
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
	if (merge.size() >= 2)
		merge.erase(merge.begin(), merge.begin() + 2);
	merge.push_back(insert);
}

void	SortVeq(std::vector<unsigned int>& vec)
{
	int				i;
	int 			size;
	unsigned int	tmp;

	i = 0;
	size = vec.size();
	while (i < size - 1)
	{
		if (vec[i] > vec[i + 1])
		{
			tmp = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	VectorInsertionSort(std::vector<unsigned int>& vec, std::vector<std::vector<unsigned int> > merge)
{
	int				i;
	int				j;
	int				size;

	size = merge.size();
	i = 0;
	while (i < size)
	{
		SortVeq(merge[i]);
		i++;
	}
	while (size != 1)
	{
		i = 0;
		j = i + 1;
		if (j < size)
			VecInsertion(merge, merge[i], merge[j]);
		i++;
		size = merge.size();
	}
	vec.assign(merge[0].begin(), merge[0].end());
}

void	VectorMergeSort(std::vector<unsigned int>& vec, std::vector<std::vector<unsigned int> >& merge, int div)
{
	int size;
	int	mid;
	std::vector<unsigned int> 				left_chunk;
	std::vector<unsigned int> 				right_chunk;

	size = vec.size();
	if (size > div)
	{
		mid = size / 2;
		left_chunk.assign(vec.begin(), vec.begin() + mid);
		right_chunk.assign(vec.begin() + mid, vec.end());
		VectorMergeSort(left_chunk, merge, div);
		VectorMergeSort(right_chunk, merge, div);
	}
	else
		merge.push_back(vec);
}

void	SortVector(std::vector<unsigned int>& vec)
{
	int div;
	int size;
	std::vector<std::vector<unsigned int> > merge;

	size = vec.size();
	if (size == 1)
		return;
	if (size < 10)
		div = 2;
	else if (size < 100)
		div = 10;
	else 
		div = 20;
	VectorMergeSort(vec, merge, div);
	VectorInsertionSort(vec, merge);
}
