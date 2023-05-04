/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:55:32 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/04 19:29:57 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

std::vector<unsigned int>	MergeInsertionVec(std::vector<unsigned int> tmp1, std::vector<unsigned int> tmp2)
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

	while (div > 1)
	{
		i = 0;
		j = 0;
		while (i < div)
		{
			tmp[j] = MergeInsertionVec(tmp[i], tmp[i + 1]);
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

	size = vec.size();
	if (size == 1)
		return;
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
	if (size % div)
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
	VectorMergeSort(vec, tmp, div);
}
