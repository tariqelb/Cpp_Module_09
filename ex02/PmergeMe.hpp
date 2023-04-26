/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:17:04 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/26 20:08:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <sys/time.h>
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
		int								FillAndCheckForErrors(int ac, char **av);
		void							SortAndDisplayResult(void);
		void							IsVectorSorted(void);
		void							IsDequeSorted(void);
};

void    SortVector(std::vector<unsigned int>& vec);
void    SortDeque(std::deque<unsigned int>& deq);

#endif
