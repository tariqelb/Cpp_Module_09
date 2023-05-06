/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:30:31 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/05/05 21:39:25 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	number;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	if (number.FillAndCheckForErrors(ac, av))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	number.SortAndDisplayResult();
	//number.IsVectorSorted();
	//number.IsDequeSorted();
	return (0);
}
