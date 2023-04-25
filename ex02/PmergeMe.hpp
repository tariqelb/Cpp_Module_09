/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:17:04 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/25 14:39:52 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<unsigned int>	vec_nbr;
		std::deque<unsigned int>	deq_nbr;

	public:
		PmergeMe();
		PmergeMe(PmergeMe& rhs);
		PmergeMe&	operator=(PmergeMe& rhs);
		~PmergeMe();

		std::vector<unsigned int>&		GetVectorNumbers(void);
		std::deque<unsigned int>&		GetDequeNumbers(void);
		int								CheckForErrors(int ac, char **av);
		void							FillContainers(int ac, char **av);
		void							DisplaySortedResult(void);

};

#endif