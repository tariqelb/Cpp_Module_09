/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 02:49:40 by tel-bouh          #+#    #+#             */
/*   Updated: 2023/04/25 03:26:16 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>

int	main(int ac, char **av)
{
	int 				i;
	int 				j;
	int 				size;
	std::deque<int>		srt;
	std::time_t			be_time;
	std::time_t			af_time;
	unsigned int		spent;
	std::string			numbers;
	if (ac != 2)
		return (1);
	i = 0;
	numbers = av[1];
	size = numbers.size();
	while (i < size)
	{
		while (i < size && numbers[i] == ' ')
			i++;
		j = 0;
		while (i + j < size && (numbers[i + j] >= '0' && numbers[i + j] <= '9'))
			j++;
		std::cout << "The j : " << j << "The i : " << i << std::endl; 
		if (j)
			srt.push_back(atoi(numbers.substr(i, j).c_str()));
		if (j)
			i = i + j;
		else
			i++;
	}
	i = 0;
	size = srt.size();
	std::cout << "Before : ";
	while (i < size)
	{
		std::cout << srt[i] << ", ";
		i++;
	}
	std::cout << std::endl;
	be_time = std::time(nullptr);
	std::sort(srt.begin(), srt.end());
	af_time = std::time(nullptr);
	i = 0;
	size = srt.size();
	std::cout << "After : " ;
	while (i < size)
	{
		std::cout << srt[i] << ", ";
		i++;
	}
	std::cout << std::endl;
	spent = af_time - be_time;
	std::cout << "Time before sort : " << be_time << std::endl;
	std::cout << "Time after  sort : " << af_time << std::endl;
	std::cout << "the spent time to sort this set of numbers is : " << spent << std::endl;
	
	be_time = std::time(nullptr);
	sleep(10);	
	sleep(10);	
	sleep(10);	
	sleep(10);	
	sleep(10);	
	sleep(10);	
	sleep(10);	
	sleep(10);	
	af_time = std::time(nullptr);
	std::cout << "Time before sort : " << be_time << std::endl;
	std::cout << "Time after  sort : " << af_time << std::endl;
	return (0);
}

